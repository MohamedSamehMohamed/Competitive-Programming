#include <bits/stdc++.h>
using namespace std;
const int N = 16;
int dp[N][1<<N], a[N][N], val[N][1<<N], n;
int vis[N][1<<N], vid;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
bool getBit(int msk, int p)
{
    return (msk >> p) & 1;
}
bool can(int curMask, int newMask)
{
    for (int i = 0; i < n; ++i)
        if (getBit(newMask, i) == 1)
        {
            if (i - 1 >= 0 && (getBit(curMask, i - 1) == 1 || getBit(newMask, i - 1) == 1))
                return false;
            if (i + 1 < n && (getBit(curMask, i + 1) == 1 || getBit(newMask, i + 1) == 1))
                return false;
            if (getBit(curMask, i) == 1)
                return false;
        }
    return true;
}
vector<int> valid[1<<N][N];
int getval(int row, int msk)
{
    int ret = 0;
    for(int i = 0; i < n; i++)
        if (msk & (1<<i))
            ret += a[row][i];
    return ret;
}
int solve(int i = 0, int msk = 0)
{
    if (i == n)return 0;
    int &ret = dp[i][msk];
    if (vis[i][msk] == vid)return ret;
    vis[i][msk] = vid;
    ret = 0;
    if (valid[msk][n].size() == 0)
    {
        for(int j = 0; j < (1<<n); j++)
        {
            if (can(msk, j))
            {
                ret = max(ret, val[i][j] + solve(i+1, j));
                valid[msk][n].push_back(j);
            }
        }
        return ret;
    }
    for(auto cur: valid[msk][n])
    {
        ret = max(ret, val[i][cur] + solve(i+1, cur));
    }
    return  ret;
}

void test()
{
    vid++;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", a[i] + j);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < (1<<n); j++)
            val[i][j] = getval(i, j);

    printf("%d\n", solve());

}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}

