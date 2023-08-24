// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int a[N], n;
/*
 * let array be x, y, z, a, b, c
 * and
 * x + y + z == a + b + c
 * then if remove c array is good if
 * [1]: (x+y+z+a+b) is odd
 * or
 * [2]: no subset with sum (x+y+z+a+b) / 2 exist
 * lema:
 * (x+y+z+a+b+c) is even so c must be odd to reach [1]
 *
 *  x + y + z == a + b + c
 *
 */
int dp[N][N*2009];
int solve(int i, int sum)
{
    if (sum < 0)return 0;
    if (i == n)return sum == 0;
    int &ret = dp[i][sum];
    if (~ret)return ret;
    ret = solve(i+1, sum);
    ret = max(ret, solve(i+1, sum - a[i]));
    return ret;
}
int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    int idx = -1, sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a+i);
        if (a[i] % 2)
            idx = i;
        sum += a[i];
    }
    if (sum % 2 || !solve(0, sum/2))
    {
        printf("0\n");
        return 0;
    }
    if (idx == -1)
    {
        int mn = 1e9;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            while(a[i] % 2 == 0)
            {
                cnt++;
                a[i] >>= 1;
            }
            if (cnt < mn)
                mn = cnt, idx = i;
        }
    }
    printf("1\n%d\n", idx + 1);

}