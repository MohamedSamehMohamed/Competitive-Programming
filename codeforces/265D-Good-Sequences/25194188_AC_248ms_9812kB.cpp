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
const int M = 1e5 + 1 ; 
int n;
int a[M];
int dp[M]; 
vector<int> divs[M]; 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n ;
    for (int i =0 ; i < n ;i++)
    {
        cin >> a[i]; 
    }
    for (int i = 2 ; i < M ;i++)
    {
        for (int j = i ; j < M ;j+=i)
        divs[j].pb(i); 
    }   
    for (int i =0 ; i < n ;i++)
    {
        int cur = a[i];
        int mx = 1;
        for (auto j : divs[cur])
        {
            mx = max (mx , dp[j] + 1 );
        }
        for (auto j : divs[cur])
        {
            dp[j] = max (dp[j] , mx );
        }
    }
    int ans =1;
    for (int i=0; i < M ;i++)ans = max (ans , dp[i]); 
    cout << ans <<"\n";
    
}
