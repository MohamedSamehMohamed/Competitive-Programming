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
const int N = 1e4;
vector<pair<int,int>> adj[N];
int root, ans;
void dfs(int u = root, int p = root, int cur = 0)
{
  if (cur > ans)
  {
    ans = cur;
    root = u;
  }
  for (auto i : adj[u])
    if (i.f != p)dfs(i.f, u, cur + i.s);
}
void solve()
{
  ans = 0;
  root = 0;
  dfs();
  dfs();
  cout << ans <<"\n";
}
int a[3];
void get_int(string x)
{
  x+=" ";
  string tm = "";
  for (int i = 0, j = 0; i < SZ(x); i++)
  {
    if (x[i] == ' ')
    {
      a[j++] = atoi(tm.c_str());
      tm = "";
    }else
    tm += x[i];
  }
  a[0]--;
  a[1]--;
  adj[a[0]].pb({a[1], a[2]});
  adj[a[1]].pb({a[0], a[2]});
}
int main()
{
  string x;
  while(getline(cin, x))
  {
    if (x == "")
    {
      solve();
      for (int i = 0; i < N; i++)adj[i].clear();
    }else
    {
      get_int(x);
    }
  }
  solve();
}
