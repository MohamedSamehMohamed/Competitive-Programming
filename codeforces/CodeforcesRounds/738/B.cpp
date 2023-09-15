// Author: Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
string x;
int n;
int dp[200][3];
int mp(char x)
{
    return x == 'B'? 1: 0;
}
int solve(int i = 0, int lst = 2)
{
    if (i == n)return 0;
    int &ret = dp[i][lst];
    if (~ret)return ret;
    if (x[i] != '?')
        ret = (lst == mp(x[i])) + solve(i+1, mp(x[i]));
    else
    {
        ret = min( (lst == 0) + solve(i+1, 0), (lst == 1) + solve(i+1, 1) );
    }
    return ret;
}
void build(int i = 0, int lst = 2)
{
    if (i == n)return;
    int ret = dp[i][lst];
    if (x[i] != '?')
        build(i+1, mp(x[i]));
    else
    {
        if (ret == (lst == 0) + solve(i+1, 0))
        {
            x[i] = 'R';
            build(i+1, 0);
        }else
        {
            x[i] = 'B';
            build(i+1, 1);
        }
    }
}
void test()
{
    cin >> n >> x;
    memset(dp, -1, sizeof dp);
    solve();
    build();
    cout << x <<"\n";
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}