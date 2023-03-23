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
int n;
const int M = 1e5 ;
int a[M][3]; 
int dp[M][3];
int main ()
{   
    scanf("%d" , &n );
    for (int i=0 ; i < n ;i++)
    {
        scanf ("%d%d%d" ,a[i] , a[i]+1, a[i]+2); 
    }
    for (int j =0 ; j < 3 ;j++)
    dp[0][j] = a[0][j]; 
    for (int i = 1; i < n ;i++)
    {
        for (int j =0 ; j< 3 ;j++)
        dp[i][j] = max (dp[i][j] , a[i][j] + max (  dp[i-1][ (j-1+3)%3 ] , dp[i-1][(j+1)%3]  ));
    }
    printf ("%d\n" , max ({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]}));
}