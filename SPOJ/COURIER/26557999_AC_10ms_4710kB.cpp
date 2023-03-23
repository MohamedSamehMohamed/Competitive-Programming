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
const int N = 107;
const ll Mx = 1e18;
int n, m, b;
ll floyed[N][N];
int a[N][2];
ll dp[N][(1<<13)];
int vis[N][(1<<13)], id;
ll solve(int lst = b, int msk = 0)
{
  if (msk == (1<<n)-1)return floyed[lst][b];
  ll &ret = dp[lst][msk];
  if (vis[lst][msk] == id)return ret;
  ret=  Mx;
  vis[lst][msk] = id;
  for (int i = 0; i < n; i++)
  {
    if ( msk & (1<<i) )continue;
    ret = min(ret, floyed[lst][a[i][0]] + floyed[a[i][0]][a[i][1]] + solve(a[i][1], msk | (1<<i)));
  }
  return ret;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    id++;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        floyed[i][j] = ( i == j ? 0: Mx);

    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      floyed[u][v] = floyed[v][u] = min(floyed[u][v], 1LL*c);
    }

    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          floyed[i][j] = min(floyed[i][j], floyed[i][k] + floyed[k][j]);
    int q;
    cin >> q;
    n = 0;
    while(q--)
    {
      int u, v, bi;
      cin >> u >> v >> bi;
      while(bi--){
      a[n][0] = u;
      a[n++][1] = v;
      }
    }
    cout << solve() <<"\n";
  }
}
