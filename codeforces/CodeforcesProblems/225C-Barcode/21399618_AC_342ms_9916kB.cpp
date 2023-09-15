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
int n , m , x, y ;
string s[1000];
int pre[1000][2];
int dp[1000][1000][2];
int solve (int cur , int con , bool col )
{
    if (con > y )return 1e9 ;
    if (cur == m )
    {
        if (con != 0 )
        {
            if (con < x )return 1e9 ;
        }
        return 0 ;
    }
    int &ret = dp[cur][con][col];
    if (~ret)return ret ;
    ret = 1e9 ;
    if (cur == 0 )
    {
        ret = min (ret ,pre[cur][1] + solve(cur + 1 , 1 , 0 ) );
        ret = min (ret , pre[cur][0] + solve(cur + 1 ,1 , 1 )) ;
    }else
    {
        if (con >= x )
            ret = min (ret , pre[cur][ col ] + solve(cur + 1 , 1 , !col ));
        ret = min (ret , pre[cur][!col] + solve(cur + 1, con + 1 , col ));
    }
    return ret ;
}
int main()
{
    memset(dp ,-1 ,sizeof dp);
    cin >> n >> m >> x >> y ;
    for (int i =0 ; i < n ;i++)cin >> s[i];
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < m ;j++)
        {
            if (s[i][j] == '#')
            {
                pre[j][0]++;
            }else
            pre[j][1]++;
        }
    }
    cout << solve(0,0,0) <<"\n";

}
