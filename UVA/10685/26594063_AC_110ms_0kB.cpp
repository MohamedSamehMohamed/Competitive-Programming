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
const int N = 5e3+9;
int n, m, par[N], size[N];
map<string, int> mp;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[v] = u;
  size[u]+=size[v];
}
int main()
{
  while(cin >> n >> m && (n || m))
  {
    mp.clear();
    for (int i = 0; i < n; i++)
    {
      size[i] = 1;
      par[i]  = i;
      string x;cin >> x;
      mp[x] = SZ(mp);
    }
    for (int i = 0; i < m; i++)
    {
      string x, y;
      cin >> x >> y;
      int u = mp[x];
      int v = mp[y];
      conect(u, v);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    ans = max(ans, size[get_par(i)]);
    cout << ans <<"\n";
  }
}
