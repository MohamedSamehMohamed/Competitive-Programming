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
int t, n;
const int M = 1000;
string s ;
int dp[M][M];
int solve (int l =0 , int r = n-1 )
{
    if (l >= r )return 0;
    int &ret = dp[l][r];
    if (~ret)return ret ;
    ret = M+M; 
    if (s[l] == s[r])ret = solve(l+1 , r-1); 
    ret = min(ret , 1 + solve(l+1 , r));
    ret = min (ret , 1 + solve(l , r-1));
    ret = min(ret , 1 + solve(l+1 ,r-1)); 
    return ret ;
}
int main ()
{   
    cin >> t ;
    for (int it = 1 ; it <= t;it++)
    {
        cin >> s ;
        n = SZ(s); 
        memset(dp , -1 ,sizeof dp);
        cout << "Case "<<it<<": "<< solve() <<"\n";

    }
}

