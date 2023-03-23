// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 51;
int n, m;
string x[N];
int vis[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main()
{
//  freopen("t.txt", "r", stdin);
  while(cin >> n >> m)
  {
    swap(n, m);
    for (int i = 0; i < n; i++)
      cin >> x[i];
    memset(vis, 0, sizeof vis);
    int px, py;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (x[i][j] == 'P')px = i, py = j;
    int ans = 0;
    queue<pair<int,int>> q;
    q.push({px, py});
    while(!q.empty())
    {
      pair<int,int> cur = q.front();
      q.pop();
      if (x[cur.f][cur.s] == 'G')ans++;
      bool can_next = 1;
      for (int i = 0; i < 4; i++)
      {
        int nx = cur.f + dx[i];
        int ny = cur.s + dy[i];
        if (min(nx, ny) >= 0 && nx < n && ny < m && x[nx][ny] == 'T')can_next = 0;
      }
      for (int i = 0; i < 4 && can_next; i++)
      {
        int nx = cur.f + dx[i];
        int ny = cur.s + dy[i];
        if (min(nx, ny) < 0 || nx == n || ny == m || vis[nx][ny] || x[nx][ny] == 'T' || x[nx][ny] == '#')continue;
        vis[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
    cout << ans <<"\n";
  }
}
