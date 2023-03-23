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
const int MAXW = 1e5+1; 
ll dp[M][MAXW];
int w[M],v[M];
int N , W ;
int main ()
{   
    scanf ("%d%d" , &N ,&W); 
    for (int i =0 ; i < N ;i++)
    {
        scanf ("%d%d" ,w+i , v+i); 
    }
    for (int j = 1;  j <= W ;j++)
        if (j >= w[0])
            dp[0][j] = v[0];
    for (int i = 1; i < N ;i++)
    {
        for (int j =1 ; j <= W ;j++)
        {
            // what can I take if I Have capacity = j 
            dp[i][j] = dp[i-1][j];
            if (j >= w[i])
            {
                dp[i][j] = max (dp[i][j] , v[i] + dp[i-1][j - w[i]]);
            }
        }
    }
    printf ("%lld\n" , dp[N-1][W]); 

}