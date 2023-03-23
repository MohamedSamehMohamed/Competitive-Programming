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
const int N = 30;
string x[N];
bool vis[N][N];
int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,-1,-1,1,1};
int n;
void dfs(int i, int j)
{
  vis[i][j] = 1;
  for (int k = 0; k < 8; k++)
  {
    int nx = i + dx[k];
    int ny = j + dy[k];
    if (min(nx, ny) < 0 || max(nx, ny) >= n || vis[nx][ny] || x[nx][ny] == '0')continue;
    dfs(nx, ny);
  }
}
int main()
{
  int t = 0;
  while(cin >> n)
  {
    t++;
    int ans = 0;
    for (int i = 0; i < n; i++)
      cin >> x[i];
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (!vis[i][j] && x[i][j] == '1')
        {
          dfs(i, j);
          ans++;
        }
    printf("Image number %d contains %d war eagles.\n", t, ans);
  }
}
