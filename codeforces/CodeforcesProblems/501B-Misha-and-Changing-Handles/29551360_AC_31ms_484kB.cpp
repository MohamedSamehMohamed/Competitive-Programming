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
const int N = 2e3+9;
int par[N];
string old[N], ne[N];
string x, y;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  par[u] = v;
  ne[v] = y;
  if (old[u] == "-1")
    old[v] = x;
  else
    old[v] = old[u];
}
int main()
{
  for (int i = 0; i < N; i++)
  {
    par[i] = i;
    old[i] = "-1";
  }
  int q;
  cin >> q;
  map<string, int> mp;
  while(q--)
  {
    cin >> x >> y;
    int u = mp.find(x) == mp.end()? mp[x] = SZ(mp): mp[x];
    int v = mp.find(y) == mp.end()? mp[y] = SZ(mp): mp[y];
    uni(u, v);
  }
  set<int> al;
  for (int i = 0; i < SZ(mp); i++)al.insert(get_par(i));
  cout << SZ(al) << '\n';
  for (int i: al)
  {
    cout << old[i] << ' ' << ne[i] << '\n';
  }
}