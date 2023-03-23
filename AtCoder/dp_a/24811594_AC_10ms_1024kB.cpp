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
int a[M]; 
int dp[M];
int main ()
{
    scanf ("%d" , &n );
    for (int i =0 ; i < n ;i++)
        scanf ("%d" ,a+i); 
    dp[1] = abs(a[0] - a[1]); 
    for (int i = 2; i < n ;i++)
    {
        dp[i] = min ( abs(a[i] - a[i-1]) + dp[i-1] , abs(a[i] - a[i-2]) + dp[i-2] ); 
    }
    cout << dp[n-1] <<"\n";
}