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
int main()
{
  fact[0] = 1;
  inv[0] = pow(1, N-2);
  for (int i = 1; i < M; i++)
  {
    fact[i] = (1LL * fact[i-1] * i)%N;
    inv[i]  = pow(fact[i], N-2);
  }
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans = (ans + 1LL * C(n, i) * C(n-1, i-1))%N;
  }
  cout << (2LL * ans - n + N)%N << '\n';
}
