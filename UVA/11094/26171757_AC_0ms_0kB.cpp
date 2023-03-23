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
const int N = 21;
string x[N];
bool vis[N][N];
int n, m, ans, cur;
char land;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int px, int py)
{
  if (px < 0 || px == n)return ;
  if (vis[px][py] || x[px][py] != land)return;
  cur++;
  vis[px][py] = 1;
  for (int i = 0; i < 4; i++)
  {
    int nx = px + dx[i];
    int ny = py + dy[i];
    ny=(m+ny)%m;
    dfs(nx, ny);
  }
}
int main()
{
  while(~scanf("%d%d", &n, &m)) {
   memset(vis, 0, sizeof vis);
   for(int i = 0; i < n; i++)
       cin >> x[i];
   int px, py;
   scanf("%d%d", &px, &py);
   land = x[px][py];
   dfs(px, py);
   ans = 0;
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
           cur = 0;
           dfs(i, j);
           if(cur > ans)
               ans = cur;
       }
   }
   printf("%d\n", ans);
  }
}
