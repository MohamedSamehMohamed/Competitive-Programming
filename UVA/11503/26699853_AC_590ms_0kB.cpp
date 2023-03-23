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
  size[v] += size[u];
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    map<string, int> mp;
    cin >> n;
    for (int i = 0; i < 2*n; i++){
      par[i] = i;
      size[i] = 1;
    }
    string x, y;
    int u, v;
    for (int i = 0; i < n; i++){
    cin >> x >> y;
    u = mp.find(x) == mp.end() ? mp[x] = SZ(mp): mp[x];
    v = mp.find(y) == mp.end() ? mp[y] = SZ(mp): mp[y];
    uni(u, v);
    cout << size[get_par(u)] << '\n';
    }
  }
}
