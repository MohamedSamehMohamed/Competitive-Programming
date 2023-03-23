#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 2e5 + 9; 
int a[N], n;
int par[N];
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
int mod = 998244353; 
int seen[N];
int main()
{
  read_file();
  scanf("%d", &n);
  iota(par, par + n, 0);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i), a[i]--; 
  
  for(int i = 0; i < n; i++)
    {
      uni(a[i], a[a[i]]);
      seen[a[i]] = seen[a[a[i]]] = 1; 
    }
  map<int, int> mp;
  for(int i = 0; i < n; i++)
  {
    if (seen[i])
     mp[get_par(i)]++;
  }
  int ans = 1;
  int x = 2, y = mp.size(); 
  while(y)
  {
    if (y&1)
      ans = (1LL * ans * x) % mod;
    x = (1LL * x * x) % mod; 
    y >>= 1; 
  }
  printf("%d\n", (ans - 1 + mod)%mod);
}
