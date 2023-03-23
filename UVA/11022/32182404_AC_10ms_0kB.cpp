#include <bits/stdc++.h>
using namespace std;
const int N = 81;
string x;
int dp[N][N], Same[N][N], n;
int solve(int l = 0, int r = n-1)
{
    if (l > r)return 0;
    if (Same[l][r]) return 1;
    int &ret = dp[l][r];
    if (~ret)return ret;
    ret = 1 + solve(l+1, r);
    string sub = "";
    int len = 0;
    for(int i = l; i <= r; i++)
    {
        // take [l:i]
        sub += x[i];
        len++;
        int j = i + 1;
        ret = min(ret, solve(l, i) + solve(j, r));
        while(j + len - 1 <= r && x.substr(j, len) == sub)
        {
            j += len;
            ret = min(ret, solve(l, i) + solve(j, r));
        }
        ret = min(ret, solve(l, i) + solve(j, r));
    }
    return ret;
}
void test()
{
    n = x.size();
    memset(Same, 0, sizeof Same);
    for(int i = 0; i < n; i++)
    {
        int j = i;
        while(j < n && x[j] == x[i])
            Same[i][j++] = 1;
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve());
}
int main() {
    while(cin >> x && x[0] != '*')
        test();
    return 0;
}
/*
 * ABBABBABBABBABBABB
 * ABBABBXABBABBXABBABB
 * AAAAABAAAB
 *
 */