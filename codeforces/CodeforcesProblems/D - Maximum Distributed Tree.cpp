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
const int N = 1e5+9, M = 1e9+ 7;
int n, m;
vector<int> adj[N];
vector<ll> deg;
int cnt[N];
ll a[N];
void init()
{
  deg.clear();
  for (int i = 0; i <= n; i++)
  {
    cnt[i] = 0;
    adj[i].clear();
  }
}
void dfs(int u = 0, int p = 0)
{
  cnt[u]++;
  for (int i: adj[u])
    if (i != p){
      dfs(i, u);
      cnt[u]+=cnt[i];
    }
}
void dfs2(int u = 0, int p = 0)
{
  for (int i: adj[u])
    if (i != p){
      dfs2(i, u);
      int A = cnt[i];
      int B = n - A;
      deg.pb(1LL*A * B);
    }
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    init();
    for (int i = 0; i < n-1; i++)
    {
      int u, v;
      cin >> u >> v;
      u--;v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    cin >> m;
    for (int i = 0; i < m; i++)cin >> a[i];
    while(m < n-1)a[m++] = 1;
    dfs();
    dfs2();
    sort(all(deg));
    sort(a, a+m);
    while(m > n-1)
    {
      a[m-2]*= a[m-1];
      a[m-2]%=M;
      m--;
    }
    sort(a, a+m);
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
      ans = (ans + 1LL * deg[i] * a[i])%M;
    }
    cout << ans << '\n';
  }
}
