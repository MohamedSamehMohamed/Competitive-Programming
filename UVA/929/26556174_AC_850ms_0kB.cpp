// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e3;
int n, m, maze[N][N], cost[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dijkstra()
{
  priority_queue<array<int,3>> pq;
  memset(cost, -1, sizeof cost);
  cost[0][0] = maze[0][0];
  pq.push({-maze[0][0], 0, 0});
  while(!pq.empty())
  {
    array<int, 3> cur = pq.top();
    pq.pop();
    if (-cur[0] > cost[cur[1]][cur[2]])continue;
    if (cur[1] == n-1 && cur[2] == m-1)break;
    for (int i = 0; i < 4; i++)
    {
      int nx = dx[i] + cur[1];
      int ny = dy[i] + cur[2];
      if (min(nx, ny) < 0 || nx == n || ny == m)continue;
      if (cost[nx][ny] == -1 || cost[cur[1]][cur[2]] + maze[nx][ny] < cost[nx][ny])
      {
        cost[nx][ny] = cost[cur[1]][cur[2]] + maze[nx][ny];
        pq.push({-cost[nx][ny], nx, ny});
      }
    }
  }
  return cost[n-1][m-1];
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> maze[i][j];
    cout << dijkstra() <<"\n";
  }
}
