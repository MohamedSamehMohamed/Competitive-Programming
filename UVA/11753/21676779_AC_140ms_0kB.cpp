// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int t ;
int n , k;
int a[10000];
int dp[10000][21][21];
int sol (int l = 0, int lc = 0 , int rc =0 )
{
    int r = n-l-1-lc+rc ;
    if (l >= r )return 0;
    if (a[l] == a[r])return sol(l+1 , lc , rc );
    if (lc + rc > k)return k+1 ;
    int &ret = dp[l][lc][rc];
    if (~ret)return ret ;
    return ret = min (1 + sol(l+1 , lc , rc + 1) , 1 + sol(l  , lc + 1, rc ));
}
void solve (int T )
{
    scanf ("%d%d" , &n ,&k);
    for (int i =0 ; i < n ;i++)scanf ("%d" ,a+i );
    memset(dp , -1 ,sizeof dp );
    int ans = sol();
    printf ("Case %d: " , T );
    if (ans == 0 )printf ("Too easy\n");
    else if (ans <= k)printf ("%d\n" ,ans );
    else
        printf ("Too difficult\n");
}
int main()
{
    scanf ("%d" , &t );
    for (int i = 1; i <= t ;i++)
    {
        solve (i);
    }

}
