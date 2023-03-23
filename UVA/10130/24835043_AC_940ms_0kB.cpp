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
const int M = 1e3;
int n, t, ans;
int P[M] , W[M]; 
int dp[M][30*M+1]; 
int solve (int i , int rem )
{
    if (rem < 0)return -1e8; 
    if (i == n || rem == 0 )return 0;
    int &ret = dp[i][rem]; 
    if (~ret)return ret;  
    ret = max ( solve(i+1 , rem ) , P[i] + solve(i + 1, rem - W[i]) ); 
    return ret ; 
}
int main ()
{
    scanf ("%d" , &t ); 
    while (t--)
    {
        scanf ("%d" , &n ); 
        ans = 0; 
        memset(dp , -1 ,sizeof dp); 
        for (int i =0 ;i < n ;i++)
        {
            scanf ("%d%d" , P+i , W+i); 
        }
        int g ;
        scanf ("%d" , &g ); 
        while (g--)
        {
            int wh ;
            scanf ("%d" , &wh ); 
            ans += solve (0 , wh );
        }
        printf ("%d\n" ,ans );

    }

}