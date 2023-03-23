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
const int N = 1002;
vector<int> adj[N], rev[N];
int n, m;
bool vis[N];
stack<int> order;
void dfs(int u)
{
  vis[u] = 1;
  for (int i: adj[u])
    if (!vis[i])
      dfs(i);
  order.push(u);
}
void SCC(int u)
{
  vis[u] = 1;
  for (int i: rev[u])
    if (!vis[i])
      SCC(i);
}
int main()
{
  FAST
  while(cin >> n >> m && (n||m)){
  for (int i = 0; i < n; i++){
    adj[i].clear();
    rev[i].clear();
    string x;
    cin >> x >> x;
  }
  map<string,int> mp;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    string x, y;
    cin >> x >> y;
    x += y;
    if (mp.find(x) == mp.end()) mp[x] = SZ(mp);
    u = mp[x];
    cin >> x >> y;
    x += y;
    if (mp.find(x) == mp.end()) mp[x] = SZ(mp);
    v = mp[x];
    adj[u].pb(v);
    rev[v].pb(u);
  }
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i);
  memset(vis, 0, sizeof vis);
  int cnt = 0;
  while(!order.empty())
  {
    int cur = order.top();
    order.pop();
    if (vis[cur])continue;
    SCC(cur);
    cnt++;
  }
  cout << cnt <<"\n";
  }
}
