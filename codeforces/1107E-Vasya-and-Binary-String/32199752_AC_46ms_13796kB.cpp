#include <bits/stdc++.h>
using namespace std;
const int N = 109;
char x[N];
long long dp[N], dp1[N][N][N];
int a[N], n;
vector<pair<int, int>> v;
long long solve(int rem)
{
    if (rem <= 1)return dp[rem] = a[rem];
    long long &ret = dp[rem];
    if (~ret)return  ret;
    ret = 0;
    for(int i = 1; i <= rem; i++)
        ret = max(ret, a[i] + solve(rem-i));
    return ret;
}
long long solve1(int l = 0, int r = n-1, int prefix = 1)
{
    if (l > r)return 0;
    if (l == r)return solve(prefix);
    long long &ret = dp1[l][r][prefix];
    if (~ret)return ret;
    ret = solve(prefix) + solve1(l+1, r, 1);
    for(int i = l+1; i <= r; i++)
        if (x[i] == x[l])
            ret = max(ret, solve1(l+1, i-1, 1) + solve1(i, r, prefix + 1));
    return ret;
}
int main() {
    memset(dp1, -1, sizeof dp1);
    memset(dp, -1, sizeof dp);
    scanf("%d%s", &n, x);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i+1);
    printf("%lld\n", solve1());
    return 0;
}