// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
string x;
int k, n;
int dp[20][1<<10][2];
int vis[20][1<<10][2], vid;
int C(int x)
{
    int cnt = 0;
    for(int i = 0; i < 10; i++)
        if (x & (1<<i))
            cnt++;
    return cnt;
}
int solve(int i = 0, int msk = 0, int f1 = 0)
{
    if (C(msk) > k)return 0;
    if (i == n)
        return 1;
    int &ret = dp[i][msk][f1];
    if (vis[i][msk][f1] == vid)return ret;
    vis[i][msk][f1] = vid;
    int st = f1? (i == 0?  1: 0): x[i]-'0';
    ret = 0;
    for(int d = st; d <= 9; d++)
    {
        ret = solve(i+1, msk | (1<<d), f1| (d > (x[i] - '0') ));
        if (ret)break;
    }
    return ret;
}
void build(int i = 0, int msk = 0, int f1 = 0)
{
    if (i == n)
        return;
    int ret = dp[i][msk][f1];
    int st = f1? (i == 0? 1: 0): x[i]-'0';
    for(int d = st; d <= 9; d++)
    {
        int p1 = solve(i+1, msk | (1<<d), f1| (d > (x[i] - '0') ));
        if(p1)
        {
            cout << d;
            build(i+1, msk | (1<<d), f1| (d > (x[i] - '0') ));
            break;
        }
    }
}
void test()
{
    vid++;
    cin >> x >> k;
    n = x.size();
    solve();
    build();
    cout <<"\n";

}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test();
}