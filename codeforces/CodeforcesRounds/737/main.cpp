// Author: MohamedSameh
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, mod = 1e9 + 7;
/*
 * 2^1 = 10
 * 2^2 = 100
 * 2^3 = 1000
 * 2^4 = 10000
 *
 *
 */
long long fact[N], inv[N];
long long fast(int b, int p)
{
    if (p == 0)return 1;
    if (p&1)return 1LL * b * fast(b, p-1)%mod;
    int cur = fast(b, p/2)%mod;
    return 1LL * cur * cur%mod;
}
int C(int n, int r)
{
    return 1LL * (1LL * fact[n] * inv[r])%mod * inv[n-r] % mod;
}
long long dp[N][2], P[N], setBits, ways, steps;
int vis[N][2], vid;
int n, k;
long long solve(int i = 0, bool f = 0)
{
    if (i == k)
        return 1;
    long long &ret = dp[i][f];
    if (vis[i][f] == vid)return ret;
    vis[i][f] = vid;
    ret = 0;
    if (f)
    {
        ret = (P[n] * solve(i+1, f)%mod)%mod;
    }else
    {
        ret = (1LL * fast(setBits, n) * solve(i+1, 1) % mod)%mod;
        ret = (ret + (setBits * ways)%mod * solve(i+1, f)%mod)%mod;
    }
    return ret;
}
void test()
{
    vid++;
    scanf("%d%d", &n, &k);
    if(k == 0)
    {
        printf("1\n");
        return;
    }
    setBits = ((((fast(2, k) * fast(2, mod - 2)))%mod) + mod) % mod;
    ways = 0;
    int ones = n-1;
    if (ones % 2)ones--;
    while(ones >= 0){
        ways = (ways + C(n, n - ones))%mod;
        ones-=2;
    }
    printf("%lld\n", (solve() % mod + mod) % mod );
}
int main() {

    P[0] = 1;
    for(int i = 1; i < N; i++)
    {
        P[i] = (P[i-1] * 2)%mod;
    }
    fact[0] = 1;
    inv[0] = fast(1, mod-2);
    for (int i = 1; i < N; i++)
    {
        fact[i] = (1LL * fact[i-1] * i)%mod;
        inv[i]  = fast(fact[i], mod-2);
    }
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}