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
const int M = 1e5+1;
int dp[501][5001];
int n, k ;
int frq[M][2];
int cost[11];
int ans;
int solve(int np , int nc )
{
    if (np == 0 || nc == 0 )return 0;
    int &ret = dp[np][nc];
    if (~ret)return ret ;
    ret = solve(np-1,nc);
    for (int i=1 ; i <= min (k,nc) ;i++)
    {
        ret = max (ret , solve(np-1 , nc - i ) + cost[i] );
    }
    return ret ;
}
int main()
{
    memset(dp , -1 , sizeof dp );
    cin >> n >> k ;
    for (int i =0 ; i < n*k ;i++)
    {
        int x ;
        cin >> x ;
        frq[x][0]++;
    }
    for (int i =0 ; i < n ;i++)
    {
        int x ;
        cin >> x ;
        frq[x][1]++;
    }
    for (int i =1; i <= k ;i++)
        cin >> cost[i];
    for (int i =0 ; i < M ;i++)
    {

        if ( frq[i][1] )
            ans += solve(frq[i][1] , frq[i][0]);
    }
    cout << ans <<"\n";

}