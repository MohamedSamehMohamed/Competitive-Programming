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
const int N = 1000;
string g[N];
int n, m, cost[N][N];
pair<int,int> src, des;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int dijkstra()
{
  memset(cost, -1, sizeof cost);
  cost[src.f][src.s] = 0;
  priority_queue<array<int,3>> pq;
  pq.push({0, src.f, src.s});
  while(!pq.empty())
  {
    array<int, 3> cur = pq.top();
    pq.pop();
    if (cur[1] == des.f && cur[2] == des.s)return cost[des.f][des.s];
    for (int i = 0; i < 8; i++)
    {
      int extra = (i != g[cur[1]][cur[2]] - '0');
      int nx = dx[i] + cur[1];
      int ny = dy[i] + cur[2];
      if (min(nx, ny) < 0 || nx == n || ny == m)continue;
      if (cost[nx][ny] == -1 || cost[nx][ny] > cost[cur[1]][cur[2]] + extra)
      {
        cost[nx][ny] = extra + cost[cur[1]][cur[2]];
        pq.push({-cost[nx][ny], nx, ny});
      }
    }
  }
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> g[i];
  int q;
  cin >> q;
  while(q--)
  {
    cin >> src.f >> src.s >> des.f >> des.s;
    src.f--;src.s--;des.f--;des.s--;
    cout << dijkstra() <<"\n";
  }
}
