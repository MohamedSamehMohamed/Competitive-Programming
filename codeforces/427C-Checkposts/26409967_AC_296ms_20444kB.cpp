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
const int N = 1e5+9, M = 1e9+7;
vector<int> adj[N], rev[N], SCC[N];
stack<int> order;
int n, m, idx, id;
int cost[N], vis[N], Mn[N];
void dfs(int u)
{
  vis[u] = id;
  for (int i : adj[u])
    if (vis[i] != id)
      dfs(i);
  order.push(u);
}
map<int,int> frq;
void dfs2(int u)
{
  vis[u] = id;
  for (int i: rev[u])
    if (vis[i] != id)
      dfs2(i);
  SCC[idx].pb(u);
  if (Mn[idx] == -1)Mn[idx] = cost[u];
  Mn[idx] = min(Mn[idx], cost[u]);
  frq[cost[u]]++; 
}
int main()
{
  memset(Mn, -1, sizeof Mn);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", cost+i);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].pb(v);
    rev[v].pb(u);
  }
  id++;
  for (int i = 0; i < n; i++)
    if (vis[i] != id)
      dfs(i);
  id++;
  ll ans = 0;
  ll ways = 1;
  while(!order.empty())
  {
    int cur = order.top();
    order.pop();
    if (vis[cur] == id)continue;
    dfs2(cur);
    ans += Mn[idx];
    ways = (ways * frq[Mn[idx]])%M;
    idx++;
    frq.clear();
  }
  printf("%lld %lld", ans, ways);

}
