// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int mod = 998244353;
int pow(int n, int p)
{
  int ret = 1;
  while(p)
  {
    if (p&1)
      ret = (1LL * ret * n) % mod;
    n = (1LL*n * n)%mod;
    p/=2;
  }
  return ret;
}
int Fact(int n)
{
  int ret = 1;
  for (int i = 2; i <= n; i++)
    ret = (1LL*ret * i) % mod;
  return ret;
}
int inv(int n)
{
  return pow(n, mod-2);
}
int C(int r, int c)
{
  return (1LL * (1LL*Fact(r) * inv(Fact(r-c)))%mod * inv(Fact(c)))%mod;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v(2*n);
  for (int i = 0; i < 2 * n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = (ans + v[2*n-1-i] - v[i])%mod;
  }
  cout << ans * C(2*n, n) % mod << '\n';
}
