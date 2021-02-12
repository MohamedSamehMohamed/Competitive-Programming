// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
#include<deque>
#include <sstream>
#include <string.h>

typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf ("%d" , &n ) 
#define LN(n) scanf ("%lld" , &n)
#define FOR(st,n) for (int i = st ; i < n ; i++)
using namespace std ;
int T ; 
int n , g , mw ; 
int p[1000],w[1000];
int dp[1000][31]; 
int sol (int i , int rem )
{
    if (i == n)return 0 ; 
    if (dp[i][rem] != -1 )return dp[i][rem];
    int s1 = sol(i+1 , rem ); // leave 
    int s2 = 0; 
    if (rem >= w[i])s2 = sol (i+1 , rem - w[i]) + p[i]; 
    return dp[i][rem] = max (s1 ,s2 ); 
}
int main ()
{
    IN(T);
    while (T--)
    {
        memset ( dp , -1 , sizeof dp ); 
        IN(n); 
        for (int i =0 ; i < n ;i++)
        {
            IN(p[i]); 
            IN(w[i]); 
        }
        IN(g);
        int ans =0 ; 
        for (int i =0 ; i < g; i++)
        {
            IN(mw);
            ans += sol (0 , mw ); 
        }
        printf ("%d\n" , ans );
    }
      return 0;
}