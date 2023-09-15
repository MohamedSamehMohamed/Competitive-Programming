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
int n, color[N], frq[N], ans, cnt;
vector<int> adj[N];
bool ok;
void dfs(int u, int p, set<int> &st)
{
  cnt = max(cnt, SZ(st));
  for (int i: adj[u])
    if (i != p)
    {
      st.insert(color[i]);
      dfs(i, u, st);
    }
}
void can(int u)
{
  for (int i: adj[u])
  {
    cnt = 0;
    set<int> st;
    st.insert(color[i]);
    dfs(i, u, st);
    if (cnt > 1)return;
  }
  ok = 1;
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
  if (ok)
    cout << "YES\n" << ans << '\n';
  else
    cout << "NO\n";
}
