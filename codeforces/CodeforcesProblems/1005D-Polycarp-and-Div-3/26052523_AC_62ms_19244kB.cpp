// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
string x;
int n ;
int dp[200000][4][2];
int solve(int i =0 , int sum =0 , bool tk =0)
{
    sum %= 3;
    if (i == n )
    {
        return (sum % 3 == 0) && tk ;
    }
    int &ret = dp[i][sum][tk];
    if (~ret)return ret;
    ret = solve(i+1,0,0);
    ret = max(ret,solve(i+1,sum+(x[i]-'0'),1));
    int ret1 = (sum % 3 == 0 && tk ) + solve(i+1 , x[i] - '0' , 1);
    ret = max (ret , ret1 );
    return ret ;
}
int main()
{
    cin >> x;
    n = SZ(x);
    memset(dp , -1 ,sizeof dp);
    cout << solve() <<"\n";
}