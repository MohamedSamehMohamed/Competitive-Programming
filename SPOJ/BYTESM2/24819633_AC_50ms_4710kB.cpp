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
int n, m ;
const int M = 100;
int a[M][M]; 
int dp[M][M]; 
int ans ;
void test ()
{
    ans =0 ;
    scanf ("%d%d" , &n ,&m); 
    memset(dp , 0 ,sizeof dp); 
    for (int i =0 ;i < n ;i++)
        for (int j =0 ; j < m;j++)
            scanf ("%d" ,a[i]+j); 
    for (int i =0 ; i < m ;i++)
    {
        dp[0][i] = a[0][i]; 
    }
    for (int i= 1; i < n ;i++)
    {
        for (int j = 0 ; j < m ;j++)
        {
            dp[i][j] = max (dp[i][j] , a[i][j] + dp[i-1][j]);
            if (j-1 >= 0 )
            dp[i][j] = max (dp[i][j] , a[i][j] + dp[i-1][j-1]);
            if (j+1 < m)
            dp[i][j] = max (dp[i][j] , a[i][j] + dp[i-1][j+1]);
        }
    }
    for (int i = 0 ; i < m;i++)
        ans = max (ans , dp[n-1][i]); 
    printf ("%d\n" , ans );

}
int main ()
{
    int t;
    scanf ("%d" , &t); 
    while (t--)
    test();
}