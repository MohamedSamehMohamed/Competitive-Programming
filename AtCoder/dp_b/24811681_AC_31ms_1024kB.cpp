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
int n, k;
const int M = 1e5 ;
int a[M]; 
int dp[M];
int main ()
{
    scanf ("%d%d" , &n , &k );
    for (int i =0 ; i < n ;i++)
        scanf ("%d" ,a+i);
    for (int i = 1; i < n ;i++)
    dp[i] = (int)2e9;
    for (int i = 1; i < n ;i++)
    {
        for (int j=0 ; j <= k && i - j >=0 ;j++)
        {
            dp[i] = min(dp[i] , abs(a[i] - a[i-j]) + dp[i-j] );
        }
    }
    cout << dp[n-1] <<"\n";
}