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
int n, m, k;
ll a[5001]; 
ll dp[5001][5001];
ll solve(int i=1, int rem=k)
{
    if (rem == 0 )return 0 ; 
    if (i == n+1)
    {
        return -1e12 ; 
    }
    ll &ret = dp[i][rem];
    if (~ret)return ret ; 
    ret = solve(i+1 , rem ); 
    if (i + m <= n+1 )
    ret = max (ret , a[i+m-1] - a[i-1] + solve(i+m , rem - 1 ));
    return ret ; 
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k ;
    for (int i =1 ;i <= n ;i++)
    {
        cin >> a[i];
        a[i] += a[i-1]; 
    }  
    memset(dp ,-1 ,sizeof dp);
    cout << solve() <<"\n"; 
}
