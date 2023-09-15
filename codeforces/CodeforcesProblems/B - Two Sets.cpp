// Author : Mohamed sameh
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
const int N = 1e5+9;
int n, a, b;
int v[N], par[N], ans[N], tem[N];
int get_par(int u)
{
 return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
 u = get_par(u);
 v = get_par(v);
 if (u == v)return ;
 par[u] = v; 
}
int main()
{
 cin >> n >> a >> b;
 map<int, int> mp;
 for (int i = 0; i < n; i++)cin >> v[i], mp[v[i]]=i, par[i] = i, ans[i]=3;
 for (int i = 0; i < n; i++)
 {
  int ax = a - v[i];
  int bx = b - v[i];
  if (mp.find(ax) != mp.end())uni(i, mp[ax]), tem[i]|=1;
  if (mp.find(bx) != mp.end())uni(i, mp[bx]), tem[i]|=2;
 }
 for (int i = 0; i < n; i++)ans[get_par(i)]&=tem[i];
 for (int i = 0; i < n; i++)if (ans[i] == 0)
 {
  cout << "NO\n";return 0;
 }
 cout <<"YES\n";
 for (int i = 0; i < n; i++)cout << (ans[get_par(i)]%2 == 0)<< " ";
 
 
}
