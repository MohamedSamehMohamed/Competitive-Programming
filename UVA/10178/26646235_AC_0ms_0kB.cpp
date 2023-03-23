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
const int N = 1e5;
int par[N];
int n, m;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
bool uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0;
  par[u] = v;
  return 1;
}
int main()
{
  while(cin >> n >> m)
  {
    for (int i = 0; i < n; i++)par[i] = i;
    map<char, int> mp;
    int sets = n+1;
    for (int i = 0; i < m; i++)
    {
      char c1, c2;
      cin >> c1 >> c2;
      int u, v;
      u = (mp.find(c1) == mp.end()? mp[c1] = SZ(mp): mp[c1]);
      v = (mp.find(c2) == mp.end()? mp[c2] = SZ(mp): mp[c2]);
      if (uni(u, v))
      {
        sets--;
      }
    }
    cout << m - n + sets  <<"\n";
  }
}
