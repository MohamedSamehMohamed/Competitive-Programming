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
const int N = 1001;
int R, C;
bool g[N][N];
int cost[N][N];
pair<int,int> src, des;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int BFS()
{
  memset(cost, -1, sizeof cost);
  cost[src.f][src.s] = 0;
  queue<pair<int,int>> q;
  q.push(src);
  while(!q.empty())
  {
    auto cur = q.front();
    q.pop();
    if (cur == des)return cost[cur.f][cur.s];
    for (int i = 0; i < 4; i++)
    {
      int nx = dx[i] + cur.f;
      int ny = dy[i] + cur.s;
      if (min(nx, ny) < 0 || nx == R || ny == C || g[nx][ny])continue;
      if (cost[nx][ny] == -1 || cost[cur.f][cur.s] + 1 < cost[nx][ny])
      {
        cost[nx][ny] = cost[cur.f][cur.s] + 1;
        q.push({nx, ny});
      }
    }

  }
  return -1;
}
int main()
{
  while(cin >> R >> C && (R || C))
  {
    memset(g, 0, sizeof g);
    int r;cin >> r;
    while(r--)
    {
      int row, num, col;
      cin >> row >> num;
      while(num--)
      {
        cin >> col;
        g[row][col] = 1;
      }
    }
    cin >> src.f >> src.s >> des.f >> des.s;
    cout << BFS() <<"\n";

  }
}
