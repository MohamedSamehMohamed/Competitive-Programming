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
const int M = 1e2;
int n, t, sum ;
int dp[M][500*M+1];
int a[M]; 
int solve (int i = 0 , int cur =0)
{
    if (i == n )return abs ((sum - cur) - cur  ); 
    int &ret = dp[i][cur]; 
    if (~ret)return ret ; 
    ret = min (  solve(i+1 , cur )   ,  solve(i+1 , cur + a[i] ) );
    return ret ;  
}
int main ()
{
    scanf ("%d" , &t ); 
    while (t--)
    {
        scanf ("%d" , &n ); 
        memset(dp , -1 ,sizeof dp); 
        sum =0 ;
        for (int i =0 ; i < n ;i++)
        {
            scanf ("%d" ,a+i);
            sum += a[i];
        }
        printf ("%d\n" , solve());
    }

}