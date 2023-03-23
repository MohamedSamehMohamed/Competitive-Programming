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
using namespace std ;
const int N = 2e5+9;
int n, t;
int par[N], size[N];
void init()
{
  for (int i = 0; i < N; i++)
  {
    par[i] = i;
    size[i] = 1;
  }
}
int get_par(int u)
{
  return u == par[u]? u : par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
  size[v] += size[u];
}
int main()
{
  cin >> t;
  while(t--)
  {
    map<string, int> mp;
    cin >> n;
    init();
    for (int i = 0; i < n; i++)
    {
      string x, y;
      cin >> x >> y;
      int u, v;
      u = mp.find(x) == mp.end()? mp[x] = SZ(mp): mp[x];
      v = mp.find(y) == mp.end()? mp[y] = SZ(mp): mp[y];
      uni(u, v);
      cout << size[get_par(u)] << '\n';
    }
  }
}
