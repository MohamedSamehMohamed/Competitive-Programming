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
const int N = 30009;
int n, m;
int par[N];
int get_par(int u)
{
  return u == par[u] ? u : par[u] = get_par(par[u]);
}
void conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u != v)par[u] = v;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)par[i] = i;
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      conect(u, v);
    }
    map<int,int> mp;
    int ans = 1;
    for (int i = 1; i <= n; i++)mp[get_par(i)]++, ans = max(ans, mp[get_par(i)]);
    cout << ans <<"\n"; 
  }
}
