// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
bool cmp (pair<int,int> a , pair<int,int> b )
{
    if (a.f != b.f )return a.f > b.f ;
    return a.s < b.s ;
}
class FarmvilleDiv2
{
int dp[51][5001];
int a[51];
int b[51];
int n ;
int solve (int cur  , int rem )
{
    if (rem < 0 )return 1e9 ;
    if (cur == n )
    {
        return 0 ;
    }
    int &ret = dp[cur][rem];
    if (~ret)return ret;
    ret = 1e9 ;
    ret = a[cur] + solve(cur + 1, rem );
    int curT = a[cur];
    while (rem > 0 && rem >= b[cur] && curT > 0 )
    {
        rem -= b[cur];
        curT--;
        ret = min (ret ,curT + solve(cur + 1 , rem ) );
    }
    return ret ;
}
public :
int minTime(vector<int> time, vector<int> cost, int budget)
{
    memset(dp , -1 ,sizeof dp );
    n = time.size() ;
    for (int i =0 ; i < n ;i++)a[i] = time[i];
    for (int i =0 ; i < n ;i++)b[i] = cost[i];
    return solve(0 , budget ) ;
}
};
