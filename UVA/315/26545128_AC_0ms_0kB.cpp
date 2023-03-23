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
vector<string> Extract(string x)
{
  vector<string> ret;
  string cur = "";
  for (int i = 0; i < SZ(x); i++)
  {
    if (x[i] == ' ' || i+1 == SZ(x))
    {
      if (i+1 == SZ(x))cur += x[i];
      ret.pb(cur);
      cur = "";
      continue;
    }
    cur += x[i];
  }
  return ret;
}
const int N = 1000;
vector<int> adj[N];
int Tin[N], low[N], vis[N], id, Time, ans;
void dfs(int u = 0, int p = -1)
{
  Tin[u] = low[u] = Time++;
  vis[u] = id;
  int childrean = 0;
  bool art = 0;
  for (int i: adj[u])
  {
    if (i == p)continue;
    if (vis[i] == id) low[u] = min(low[u], Tin[i]);
    else
    {
      dfs(i, u);
      low[u] = min(low[u], low[i]);
      childrean++;
      if (low[i] >= Tin[u] && p != -1)art = 1;
    }
  }
  if (childrean > 1 && p == -1)art = 1;
  ans += art;
}
int main()
{
  int n;
  while(cin >> n && n)
  {
    id++;
    Time = ans = 0;
    for (int i = 0; i < n; i++) adj[i].clear();
    for(int i = 0; ; i++)
    {
      string x = "";
      while(SZ(x) == 0)getline(cin, x);
      vector<string> line = Extract(x);
      if (line[0] == "0")break;
      int u = atoi(line[0].c_str());
      for (int j = 1; j < SZ(line); j++)
        {
          int v = atoi(line[j].c_str());
          adj[u-1].pb(v-1);
          adj[v-1].pb(u-1);
        }
    }
    for (int i = 0; i < n; i++)if (vis[i] != id) dfs(i, -1);
    cout << ans  <<"\n";
  }
}
