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
const int M =2e4 + 5 ; 
int t, n, l, r ; 
int a[M]; 
int dp[M][2];
int main ()
{   
    scanf ("%d", &t );
    for (int it = 1; it <= t ;it++)
    {
        scanf ("%d" , &n ); 
        n--;
        for (int i =0 ; i < n ;i++)
        {
            scanf("%d" , a+i ); 
        }
        dp[0][0] = a[0];
        dp[0][1] = 0 ; 
        l = r = 0;
        int ans = dp[0][0]; 
        for (int i =1 ; i < n ;i++)
        {
            if (a[i] > dp[i-1][0] + a[i])
            {
                dp[i][0] = a[i];
                dp[i][1] = i;  
            }else 
            {
                dp[i][0] = a[i] + dp[i-1][0]; 
                dp[i][1] = dp[i-1][1] ; 
            }
            if (dp[i][0] > ans || (dp[i][0] == ans && i - dp[i][1] > r - l ))
            {
                ans = dp[i][0]; 
                l = dp[i][1]; 
                r = i; 
            }
        }
        
        if (ans <= 0 )
        printf ("Route %d has no nice parts\n" , it );
        else 
        printf ("The nicest part of route %d is between stops %d and %d\n" , it , l+1 , r+2 );

    }
}