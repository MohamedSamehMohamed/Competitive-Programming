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
int dp[10000][101]; 
int a[10000]; 
int n , k ;
int solve(int i  , int sum )
{

    sum %=k ; 
    sum = (sum + k )%k ;
    if (i == n)
    {
        return (sum == 0); 
    }
    int &ret = dp[i][sum]; 
    if (~ret)return ret ; 
    ret = max (  solve(i+1 , sum - a[i] ) , solve(i+1 , sum  + a[i]) );
    return ret ; 
}
int main ()
{   
    int t ; 
    scanf ("%d", &t );
    while (t--)
    {
        memset(dp , -1 ,sizeof dp); 
        scanf ("%d%d" , &n ,&k);
        for (int i =0 ; i < n ;i++)
            scanf ("%d" , a+i); 
        if (solve(1 , a[0]))
        printf ("Divisible\n"); 
        else 
        printf ("Not divisible\n"); 
    } 
}