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
const int N = 1e4;
vector<int> adj[N];
int n;
int vis[N], Tin[N], Low[N], id, tim;
set<pair<int,int>> ans;
void dfs(int u, int p)
{
  vis[u] = id;
  Tin[u] = Low[u] = tim++;
  for (int v : adj[u])
  {
    if (v == p)continue;
    if (vis[v] == id) Low[u] = min(Low[u], Tin[v]);
    else
    {
      dfs(v, u);
      Low[u] = min(Low[u], Low[v]);
      if (Low[v] > Tin[u])
        ans.insert({min(u,v), max(v,u)});
    }
  }
}
int main()
{
  while(cin >> n)
  {
    int u, v, chs;
    char c;
    for (int i = 0; i < n; i++)adj[i].clear();
    id++;
    tim = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> u >> c >> chs >> c;
      while(chs--)
      {
        cin >> v;
        adj[u].pb(v);
        adj[v].pb(u);
      }
    }
    ans.clear();
    for (int i = 0; i < n; i++)if (vis[i] != id)dfs(i, -1);
    cout << SZ(ans) <<" critical links\n";
    for (auto i: ans)
      cout << i.f <<" - " << i.s <<"\n";
    cout <<"\n";
  }
}
