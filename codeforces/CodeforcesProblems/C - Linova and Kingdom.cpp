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
const int M = 2e5 + 1; 
vector<int> adj[M];
int dp[M];
int dfs (int u =0  , int p = 0 , int h =0)
{
    int c =0 ;
    for (int i : adj[u])
    {
        if (i == p )continue ;
        c +=  1 + dfs(i , u , h+1);
    }
    dp[u] = h - c;
    return c ; 
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;ll ans =0;
    cin >> n >> k;
    for (int i =1 ; i < n ;i++)
    {
        int u, v ;
        cin >> u >> v ;u--;v--;
        adj[u].pb(v); 
        adj[v].pb(u); 
    }
    dp[0]=-dfs();
    sort(dp,dp+n);
    for (int i =n-1 ;i >= n-k;i--)
    {
        ans += dp[i];
    }
    cout << ans <<"\n";
     
}
