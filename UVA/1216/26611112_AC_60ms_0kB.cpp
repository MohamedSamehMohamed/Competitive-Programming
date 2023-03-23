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
const int N = 1e6;
int par[N];
int get_par(int u)
{
  return u == par[u] ? u: par[u] =  get_par(par[u]);
}
bool uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0;
  par[u] = v;
  return 1;
}
int dist(pair<int,int> &a, pair<int,int> &b)
{
  double d = sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
  return ceil(d);
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<pair<int,int>> tm;
    vector<array<int,3>> v;
    while(1)
    {
      int x, y;
      cin >> x;
      if (x == -1)break;
      cin >> y;
      tm.pb({x, y});
    }
    for (int i = 0; i < SZ(tm); i++)
      for (int j = i+1; j < SZ(tm); j++)
        v.pb({dist(tm[i], tm[j]), i, j});
    sort(all(v));
    for (int i = 0; i < SZ(v); i++)par[i] = i;
    vector<int> dists;
    for (int i = 0; i < SZ(v); i++)
    {
      if (uni(v[i][1], v[i][2]))
      {
        dists.pb(v[i][0]);
      }
    }
    n = SZ(tm) - n - 1;
    if (n >= 0 && n < SZ(dists))
    cout << dists[n] <<"\n";
    else
    cout << "0\n";
  }
}
