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
int n, x ;
int dp[100][10001];
int a[100];
int solve (int i =0 , int rem = x )
{
    if (rem < 0)return -1e8 ;
    if (i == n)return 0; 
    int &ret = dp[i][rem];
    if (~ret)return ret ; 
    return ret = max (solve(i+1 , rem) , 1 + solve(i+1 , rem - (n-i)*a[i]  ) ); 
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt" , "r" , stdin ); 
    freopen("output.txt" , "w" , stdout); 
    memset(dp , -1 ,sizeof dp);
    cin >> n >> x ;
    for (int i =0 ; i < n ;i++)cin >> a[i]; 
    cout << max(0,solve()) <<"\n";
}
