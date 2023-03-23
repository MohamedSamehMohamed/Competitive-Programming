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
const int N = 1e5+ 9;
int par[N], n;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
}
bool same(int u, int v)
{
  return get_par(u) == get_par(v);
}
int main()
{
  int t;
  cin >> t;
  bool f = 0;
  string x = "";
  while(t--)
  {
    if (!f)
    cin >> n;
    else
    n = atoi(x.c_str());
    f = 1;
    for (int i = 0; i < n; i++)par[i] = i;
    int a, b;
    a = 0;
    b = 0;
    while(cin >> x)
    {
      if (x[0] != 'q' && x[0] != 'c')break;
      char c = x[0];
      int u, v;
      cin >> u >> v;
      u--;v--;
      if (c == 'c')
      {
        uni(u, v);
      }else
      {
        b += !same(u, v);
        a += 1;
      }
      x = "";
    }
    a-=b;
    cout << a << "," << b <<"\n";
    if (t)cout <<"\n";
  }
}
