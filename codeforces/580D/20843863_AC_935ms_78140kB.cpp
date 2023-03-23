// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo ()
{
    fflush(stdout);
}
using namespace std ;
int cost[200][200];
int sat[200];
ll dp[(1<<19)][19];
int n , m , k ;
bool done (int mask )
{
    int x =0 ;
    for (int i =0 ; i < 20 ;i++)
        x += ( (mask & (1 << i)) > 0  );
    return x == m ;
}
ll sol (int mask , int last )
{
    if (done(mask))return 0 ;
    ll &ret = dp[mask][last];
    if (~ret)return ret ;
    for (int i =1 ; i <= n ;i++)
    {
        if ( (mask & (1<<i)) )continue ;
        int tmask = mask | (1 << i );
        ret = max (ret , 1LL * cost[last][i] + sat[i] + sol (tmask , i ));
    }
    return ret ;
}
int main ()
{
    scanf ("%d%d%d" , &n ,&m ,&k );
    for (int i =1 ; i <= n ;i++)scanf ("%d" ,sat+i );
    for (int i =0 ; i < k ;i++)
    {
        int a , b , c ;
        scanf ("%d%d%d" , &a ,&b ,&c );
        cost[a][b] = c ;
    }
    memset(dp, -1 , sizeof dp );
    printf ("%lld\n" , sol (0,0));

    return 0;
}


