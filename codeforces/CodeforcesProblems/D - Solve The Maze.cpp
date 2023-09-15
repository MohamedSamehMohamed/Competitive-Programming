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
int t, n, m;
string x[N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool vis[N][N];
void dfs(int cx, int cy)
{
 vis[cx][cy] = 1;
 for (int i = 0; i < 4; i++)
 {
  int nx = cx + dx[i];
  int ny = cy + dy[i];
  if (min(nx, ny) < 0 || nx == n || ny == m || vis[nx][ny] || x[nx][ny] == '#')continue;
  dfs(nx, ny);
 }
}
bool good()
{
 memset(vis, 0, sizeof vis);
 if (x[n-1][m-1] == '.')dfs(n-1, m-1);
 for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++)
  {
   if (x[i][j] == 'G' && !vis[i][j])return 0;
   if (x[i][j] == 'B' && vis[i][j])return 0; 
  }
 return 1;
}
void fix(int cx, int cy)
{
 for (int i = 0; i < 4; i++)
 {
  int nx = cx + dx[i];
  int ny = cy + dy[i];
  if (min(nx, ny) < 0 || nx == n || ny == m || x[nx][ny] == '#')continue;
  if (x[nx][ny] == '.')x[nx][ny] = '#';
 }
}
void blockBad()
{
 for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++)
  {
   if (x[i][j] == 'B')
   {
    fix(i, j);
   }
  }
}
int main()
{
 cin >> t;
 while(t--)
 {
  cin >> n >> m;
  for (int i = 0; i < n; i++)cin >> x[i];
  blockBad();
  cout << (good()? "Yes\n" : "No\n");
 }
}
