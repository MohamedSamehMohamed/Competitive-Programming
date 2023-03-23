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
int n ;
const int M = 1e5 + 9 ;
int X[M],H[M];
int dp[M][3];
/*
0 no cut 
1 left 
2 right 
*/
int solve (int i =0 , int st = 0)
{
    if (i == n)return 0 ;
    int &ret = dp[i][st]; 
    if (~ret)return ret ; 
    ret = solve(i+1 , 0 ); 
    if ( !i ||  (st <= 1&& X[i] - H[i] > X[i-1] ) || (X[i-1] + H[i-1] < X[i] - H[i]))
    ret = max (ret , 1 + solve(i+1 , 1));
    if (i == n-1 || X[i] + H[i] < X[i+1])
    ret = max (ret , 1 + solve(i+1 ,2 ));
    return ret ; 
} 
int main ()
{   
    scanf ("%d" , &n);
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%d%d" , X+i , H+i); 
    }
    memset(dp , -1 ,sizeof dp);
    printf ("%d\n" , solve());
    
}

