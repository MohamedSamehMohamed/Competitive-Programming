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
int n, W[N], frq[N], leaf[N];
ll sum, tot;
vector<pair<int,int>> adj[N];
priority_queue<ll> pq;
void init()
{
  tot = 0;
  for (int i = 0; i < n; i++)
  {
    adj[i].clear();
    leaf[i] = frq[i] = 0;
  }
  while(!pq.empty())pq.pop();
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
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--;v--;
      adj[u].pb({v, i});
      adj[v].pb({u, i});
      W[i] = w;
    }
    dfs();
    for (int i = 0; i < n-1; i++)
    {
      tot += 1LL * W[i] * frq[i];
      while(W[i])
      {
        pq.push(profit(i));
        W[i]/=2;
      }
    }
    int ans = 0;
    while(tot > sum)
    {
      ans++;
      tot-=pq.top();
      pq.pop();
    }
    printf("%d\n", ans);
  }
}
