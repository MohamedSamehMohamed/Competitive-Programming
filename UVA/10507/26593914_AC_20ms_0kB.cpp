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
int n, m;
const int N = 26, Mx = 1e9;
int cost[N];
map<char, int> mp;
vector<int> adj[N];
int get_int(char c)
{
  if (mp.find(c) == mp.end())mp[c] = SZ(mp);
  return mp[c];
}
int main()
{
  while(cin >> n)
  {
    mp.clear();
    cin >> m;
    string str;cin >> str;
    for (int i = 0; i < N; i++)
        cost[i] = Mx, adj[i].clear();
    for (int i = 0; i < 3; i++)
    {
      cost[get_int(str[i])] = 0;
    }
    for (int i = 0; i < m; i++)
    {
      cin >> str;
      int u = get_int(str[0]);
      int v = get_int(str[1]);
      adj[u].pb(v);
      adj[v].pb(u);
    }
    int loop = 1e4;
    while(loop--){
    for (int i = 0; i < n; i++)
    {
      vector<int> tm;
      for (int j: adj[i])
        if (cost[j] != Mx)tm.pb(cost[j]);
      if (SZ(tm) < 3)continue;
      sort(all(tm));
      int need = tm[2] + 1;
      cost[i] = min(cost[i], need);
    }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans = max(ans, cost[i]);
    }
    if (ans == Mx)
      cout <<"THIS BRAIN NEVER WAKES UP\n";
    else
      cout <<"WAKE UP IN, " << ans <<", YEARS\n";
  }
}
