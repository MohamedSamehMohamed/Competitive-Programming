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
int n, k, t ;
int a[10000]; 
map<pair<pair<int,int>,int>,int> dp ; 
int solve (int l=0, int r = n-1 , int ch =0 )
{
    if (ch > k)return ch ; 
    if (l >= r )return 0; 
    if(dp.find({{l,r},ch}) != dp.end()) return dp[{{l,r},ch}];
    if (a[l] == a[r])return solve(l+1 , r -1 , ch ); 
    return dp[{{l,r},ch}] = 1 + min(solve(l,r-1,ch+1) , solve(l+1,r,ch+1));
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t ;
    for (int it = 1; it <= t ;it++)
    {
        dp.clear();
        cin >> n >> k ; 
        for (int i =0 ; i < n ;i++)
            cin >> a[i];
        cout <<"Case " << it <<": "; 
        int ans = solve();
        if (ans == 0 )
        cout <<"Too easy";
        else if (ans <= k)
        cout << ans ; 
        else 
        cout <<"Too difficult"; 
        cout <<"\n";
    }

}