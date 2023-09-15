#include <bits/stdc++.h>
using namespace std;
const int N = 109;
char x[N];
long long dp[N][N][N];
int a[N], n;
long long solve(int l = 0, int r = n-1, int prefix = 1)
{
    if (l > r)return 0;
    if (l == r)return a[prefix];
    long long &ret = dp[l][r][prefix];
    if (~ret)return ret;
    ret = solve(l+1, r, 1) + a[prefix];
    for(int i = l+1; i <= r; i++)
        if (x[i] == x[l])
            ret = max(ret, solve(l+1, i-1, 1) + solve(i, r, prefix + 1));
    return ret;
}
int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d%s", &n, x);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i+1);
    printf("%lld\n", solve());
    return 0;
}