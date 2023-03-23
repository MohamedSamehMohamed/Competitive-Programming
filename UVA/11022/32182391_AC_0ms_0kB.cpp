#include <bits/stdc++.h>
using namespace std;
const int N = 81;
string x;
int dp[N][N], n;
bool same(int l, int r)
{
    while(l + 1 <= r && x[l] == x[l+1])
        l++;
    return l == r;
}
bool same(string str)
{
    int l = 0, r = str.size()-1;
    while(l + 1 <= r && str[l] == str[l+1])
        l++;
    return l == r;
}
int compute(string str)
{
    int len = 0;
    for(int i = 0; i < str.size(); i++)
    {
        int j = i + 1;
        while(j < str.size() && str[j] == str[j-1])
            j++;
        len++;
        i = j-1;
    }
    return len;
}
int solve(int l = 0, int r = n-1)
{
    if (l > r)return 0;
    if (same(l, r)) return 1;
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