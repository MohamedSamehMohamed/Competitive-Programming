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
const int N = 2e5+9;
int n, par[N], size[N];
map<string, int> mp;
int get_int(string x)
{
  if (mp.find(x) == mp.end())mp[x] = SZ(mp);
  return mp[x];
}
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
int conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return size[v];
  par[u] = v;
  size[v] += size[u];
  return size[v];
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    mp.clear();
    cin >> n;
    for (int i = 0; i < 2*n; i++)par[i] = i, size[i]=1;
    while(n--)
    {
      int u, v;
      string x;
      cin >> x;
      u = get_int(x);
      cin >> x;
      v = get_int(x);
      int ans = conect(u, v);
      cout << ans <<"\n";
    }
  }
}
