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
int n, m, t ; 
int a[20][2]; 
map<pair<int,ll>,ll> dp; 
ll solve (int i , int rem )
{
    if (rem <= 0 )return 0;
    if (i == n )
    {
        return 1e15 ; 
    } 
    if (dp.find({i , rem}) != dp.end())return dp[{i,rem}]; 
    ll cur = solve(i+1 , rem); 
    cur = min (cur , a[i][1] + solve(i+1 , rem - 1LL*t * a[i][0])); 
    dp[{i,rem}] = cur ; 
    return cur ; 
}
int main()
{
    cin >> n ;
    for (int i =0 ; i < n ;i++)
    {
        cin >> a[i][0] >> a[i][1]; 
    }
    cin >> m ;
    int it = 0;
    while (m--)
    {
        it++; 
        int v;
        cin >> v >> t ;
        dp.clear();
        ll cur = solve(0 , v );
        cout <<"Case " << it << ": "; 
        if (cur >= 1e15 )
        {
            cout <<"IMPOSSIBLE\n"; 
        }else 
        cout << cur <<"\n";

    }
}
