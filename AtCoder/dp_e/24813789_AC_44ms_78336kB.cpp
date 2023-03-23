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
const int M = 100 ;
const int MAXV = 1e5+1; 
const ll MAX = 2e18+9;
ll dp[M][MAXV];
int w[M],v[M];
int N , W ;
int ans ;
int main ()
{   
    scanf ("%d%d" , &N ,&W); 
    for (int i =0 ; i < N ;i++)
    {
        scanf ("%d%d" ,w+i , v+i); 
    }
    // dp[i][j] means 
    // what is the minumum weight to get the value j in range [0 : i]
    for (int i =0 ; i < N ;i++)
        for (int j =0 ; j < MAXV ;j++)
            dp[i][j] = MAX ; 
    for (int i =0 ;i < N ;i++)
        dp[i][ v[i] ] = w[i];
    for (int i =1 ; i < N ; i++)
    {
        for (int j = 1 ; j < MAXV ;j++)
        {
            dp[i][j] = min(dp[i][j] , dp[i-1][j]);
            if (j >= v[i])
            {
                dp[i][j] = min (dp[i][j] , dp[i-1][ j - v[i] ] + w[i]  );
            }
        }
    }
    
    for (int i= 0 ; i < MAXV ;i++)
    {
        if (dp[N-1][i] <= W )
            ans = max (ans , i); 
    }
    printf ("%d\n" , ans); 

}