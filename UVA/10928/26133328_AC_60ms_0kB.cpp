// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
vector<int> adj[1000];
vector<int> Extract(string x)
{
  string tm = "";
  vector<int> ret;
  for (int i = 0; i < SZ(x); i++)
  {
    if (x[i] != ' ')tm+=x[i];
    else
    {
      ret.pb(atoi(tm.c_str()));
      tm = "";
    }
  }
  return ret;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int mn = n+1;
    for (int i = 0; i < n; i++)
    {
      adj[i].clear();
      string x = "";
      while(!SZ(x))getline(cin, x);
      vector<int> ne = Extract(x);
      for (int u : ne)
      {
        adj[i].pb(u-1);
      }
      mn = min(mn, SZ(adj[i]));
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)if(SZ(adj[i]) == mn)ans.pb(i+1);
    for (int i = 0; i < SZ(ans); i++)printf("%d%c", ans[i], (i+1 == SZ(ans) ? '\n' : ' '));
  }
}
