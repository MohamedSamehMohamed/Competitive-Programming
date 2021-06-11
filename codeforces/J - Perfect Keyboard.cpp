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
string x;
set<int> adj[26];
bool vis[26];
string path;
bool cyc;
void dfs(int u, int p)
{
  vis[u] = 1;
  path += char('a' + u);
  for (int i : adj[u])
  {
    if (i == p)continue;
    if (vis[i])
    {
      cyc = 1;
      return;
    }
    dfs(i, u);
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    for (int i = 0; i < 26; i++)adj[i].clear();
    memset(vis, 0, sizeof vis);
    cin >> x;
    path = "";
    if (SZ(x) <= 2)
    {
      cout <<"YES\n";
      path = x;
      vis[x[0] - 'a']=1;
      if (SZ(x) == 2)vis[x[1] - 'a'] = 1;
      for (int i = 0; i < 26; i++)if(!vis[i])path += char('a' + i);
      cout << path <<"\n";
      continue;
    }
    for (int i = 1; i + 1 < SZ(x); i++)
    {
      int u = x[i-1] - 'a';
      int v = x[i] - 'a';
      int c = x[i+1] - 'a';
      adj[u].insert(v);
      adj[v].insert(u);
      adj[v].insert(c);
      adj[c].insert(v);
    }
    int st = -1;
    for (int i = 0; i < 26; i++)
    {
      if (SZ(adj[i]) == 1)st = i;
      if (SZ(adj[i]) > 2)
      {
        st = -1;
        break;
      }
    }
    if (st == -1)
    {
      cout <<"NO\n";
      continue;
    }
    cyc = 0;
    dfs(st, st);
    if (cyc)
    {
      cout <<"NO\n";
    }else
    {
      cout <<"YES\n";
      cout << path;
      for (int i = 0; i < 26; i++)if (!vis[i])cout << char('a' + i);
      cout <<"\n";
    }
  }
 
}
