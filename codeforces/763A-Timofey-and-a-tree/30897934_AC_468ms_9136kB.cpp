// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std;
const int N = 1e5+9;
int n, color[N], frq[N], ans, cur;
vector<int> adj[N];
bool ok;
bool OK;
void dfs(int u, int p, int curr)
{
  if (curr != cur)ok = 0;
  for (int i: adj[u])
    if (i != p)
      dfs(i, u, color[i]);
}
void can(int u)
{
  ok = 1;
  for (int i: adj[u])
  {
    cur = color[i];
    dfs(i, u, color[i]);
    if (!ok)return;
  }
  OK = 1;
  ans = u + 1;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 0; i < n; i++)
  {
    cin >> color[i];
    color[i]--;
    frq[color[i]]++;
  }
  int node1, node2;
  node1 = node2 = 0;
  for (int i = 1; i < n; i++)
  {
    if (SZ(adj[i]) > SZ(adj[node1]) || (SZ(adj[i]) == SZ(adj[node1]) && frq[color[i]] < frq[color[node1]])) node1 = i;
    if (frq[color[i]] < frq[color[node2]] || (frq[color[i]] == frq[color[node2]] && SZ(adj[i]) > SZ(adj[node2])))node2 = i;
  }
  can(node1);
  can(node2);
  if (OK)
    cout << "YES\n" << ans << '\n';
  else
    cout << "NO\n";
}