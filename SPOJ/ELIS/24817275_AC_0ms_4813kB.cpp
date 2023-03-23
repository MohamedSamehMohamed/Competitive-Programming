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
int a[10];
int dp[10];
int ans;
int main ()
{   
    cin >> n ;
    for (int i =0 ; i < n ;i++)
        cin >> a[i]; 
    for (int i =0 ; i < n ;i++)
        dp[i]=1; 
    for (int i =1 ; i < n ;i++)
    {
        for (int j = i-1 ; j>=0 ;j--)
        {
            if (a[i] > a[j])
            dp[i] = max (dp[i] , 1 + dp[j]); 
        }
    }
    for (int i =0 ; i < n ;i++)
    ans = max (ans , dp[i]); 
    cout << ans <<"\n";

}