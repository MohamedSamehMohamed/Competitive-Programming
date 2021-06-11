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
const int N = 1e5+1;
int n, W[N], frq[N], leaf[N], type[N];
ll sum, tot;
vector<pair<int,int>> adj[N];
vector<ll> ch[2];
void init()
{
  tot = 0;
  for (int i = 0; i < n; i++)
  {
    adj[i].clear();
    leaf[i] = frq[i] = 0;
  }
  ch[0].clear();
  ch[1].clear();
}
void dfs(int u = 0, int par = 0)
{
  for (auto i: adj[u])
  {
    if (i.f == par)continue;
    dfs(i.f, u);
    leaf[u] +=  leaf[i.f];
    frq[i.s] += leaf[i.f];
  }
  if (SZ(adj[u]) == 1 && u)leaf[u]++;
}
ll profit(int i)
{
  ll a = 1LL*W[i] * frq[i];
  ll b = 1LL * (W[i]/2) * frq[i];
  return a - b;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%lld", &n, &sum);
    init();
    for (int i = 0; i < n-1; i++)
    {
      int u, v, w, ty;
      scanf("%d%d%d%d", &u, &v, &w, &ty);
      u--;v--;
      adj[u].pb({v, i});
      adj[v].pb({u, i});
      W[i] = w;
      type[i] = ty;
    }
    dfs();
    for (int i = 0; i < n-1; i++)
    {
      tot += 1LL * W[i] * frq[i];
      while(W[i])
      {
        ch[type[i]-1].pb(profit(i));
        W[i]/=2;
      }
    }
    sort(rall(ch[0]));
    sort(rall(ch[1]));
    int ans = 0;
    int i, j, sz1, sz2;
    i = j = 0;
    sz1 = SZ(ch[0]);
    sz2 = SZ(ch[1]);
    while(tot > sum)
    {
      if (i < sz1 && j < sz2)
      {
        if (ch[0][i] >= ch[1][j] || (tot - ch[0][i] <= sum) || (i+1 < sz1 && ch[0][i] + ch[0][i+1] >= ch[1][j]))
        {
          ans++;
          tot -= ch[0][i];i++;
        }else
        {
          ans+=2;
          tot -= ch[1][j];j++;
        }
      }else if (i < sz1)
      {
        ans++;
        tot -= ch[0][i];i++;
      }else
      {
        ans+=2;
        tot -= ch[1][j];j++;
      }
    }
    printf("%d\n", ans);
  }
}
