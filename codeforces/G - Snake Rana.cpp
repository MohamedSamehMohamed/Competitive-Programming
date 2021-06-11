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
const int N = 1e9+7, M = 1e5+9;
int fact[M], inv[M];
int pow(int b, int p)
{
  if (p == 0)return 1;
  if (p&1)return 1LL * b * pow(b, p-1)%N;
  int cur = pow(b, p/2)%N;
  return 1LL * cur * cur%N;
}
int C(int n, int r)
{
  return 1LL * (1LL * fact[n] * inv[r])%N * inv[n-r] % N;
}
void compute()
{
  fact[0] = 1;
  inv[0] = pow(1, N-2);
  for (int i = 1; i < M; i++)
  {
    fact[i] = (1LL * fact[i-1] * i)%N;
    inv[i]  = pow(fact[i], N-2);
  }
}
int x[20], y[20];
int mxX, mxY, mnX, mnY, n, m, k;
ll solve()
{
  ll ret = 1LL * mnX * (n-mxX+1) * mnY * (m-mxY+1) ;
  return ret;
}
ll sum(int x)
{
  return (1LL * (x+1) * x)/2;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
    ll ans = 1LL * sum(n) * sum(m);
    for (int i = 1; i < (1<<k); i++)
    {
      int cnt = 0;
      mxX = mxY = -1;
      mnX = mnY = 1e9;
      for (int j = 0; j < k; j++)
        if (i & (1<<j))
        {
          cnt++;
          mxX = max(mxX, x[j]);
          mxY = max(mxY, y[j]);
          mnX = min(mnX, x[j]);
          mnY = min(mnY, y[j]);
        }
      ll cur = solve();
      if (cnt&1)cur *= -1;
      ans += cur;
    }
    cout << ans << '\n';
  }
}
