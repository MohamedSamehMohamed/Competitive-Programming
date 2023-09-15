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
const int M = 101;
int a[M];
int dp[M][4]; 
int solve (int i =0 , int last =0 )
{
    if (i == n)return 0;
    int &ret =dp[i][last];
    if (~ret)return ret ; 
    ret = 1 + solve(i+1 , 0);
    if (a[i] == 1 && last != 1 )
    {
        ret = min (ret , solve(i+1 , 1)); 
    }
    if (a[i] == 2 && last != 2 )
    {
        ret = min (ret , solve(i+1 , 2)); 
    }
    if (a[i] == 3 )
    {
        if (last != 1 )
        ret = min (ret , solve(i+1 , 1)); 
        if (last != 2)
        ret = min (ret , solve(i+1 , 2));
    }
    return ret ;
}
int main ()
{   
    scanf ("%d" , &n );
    for (int i =0 ; i < n ;i++)
        scanf ("%d" ,a+i); 
    memset(dp , -1 ,sizeof dp);
    printf ("%d\n" , solve());
}

