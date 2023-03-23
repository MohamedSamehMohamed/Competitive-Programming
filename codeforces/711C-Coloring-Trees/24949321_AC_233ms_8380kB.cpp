//https://codeforces.com/group/uiuj0r1eb7/contest/1003/problem/F
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
int n, m, k;
const ll MAX = 1e15 ; 
const int M = 102 ;
int colors[M]; 
int cost[M][M]; 
ll dp[M][M][M]; 
ll solve (int i =0 , int b =0 , int last =0  )
{
    if (i == n )
    {
        if (b == k)return 0; 
        return MAX ; 
    }
    ll &ret = dp[i][b][last]; 
    if (~ret)return ret ;
    if (colors[i] != 0 )
    {
        ret = solve(i+1 , b + (last != colors[i]) , colors[i] ); 
    }else 
    {
        ret = MAX ;
        for (int j = 1 ; j <= m ;j++)
        {
            ret = min (ret ,  cost[i][j-1] + solve(i+1 , b + (last != j) , j) );
        }
    }
    return ret ; 
}
int main()
{
    memset(dp , -1 ,sizeof dp);
    scanf("%d%d%d" , &n ,&m ,&k);
    for (int i =0 ; i < n ;i++)
    {
        scanf("%d" ,colors+i); 
    }
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < m ;j++)
        {
            scanf("%d", cost[i] + j ); 
        }
    }
    ll ans = solve();
    if (ans >= MAX )
    ans = -1 ; 
    printf ("%lld\n" , ans ); 

}
