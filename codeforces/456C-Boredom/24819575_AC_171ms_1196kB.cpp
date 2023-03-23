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
const int M = 1e5 +2 ;
int frq[M];
ll dp[M];
int main ()
{   
    cin >> n ;
    for (int i =0 ; i < n ;i++)
    {
        int u ;
        cin >> u ;
        frq[u]++; 
    }
    
    for (int i =1; i < M ;i++)
    {
        dp[i] = 1LL*frq[i]*i ;
        if (i-2>=0)dp[i]+=dp[i-2]; 
        dp[i] = max (dp[i-1],dp[i]);
    }
    cout << dp[M-1] <<"\n";

}