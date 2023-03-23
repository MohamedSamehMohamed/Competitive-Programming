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
int m, d ;
string l, r ;
int n ;
const int M = 1e9 + 7 ;
ll dp[2001][2001][2][2];
ll solve (int cur = 0, int prd  =0, bool lim =0 ,bool lim1 = 0  )
{
    if (cur == n )
    {
        return !prd ;
    }
    ll &ret = dp[cur][prd][lim][lim1];
    if (~ret)return ret ;
    int mn = (lim1 ? 0 : l[cur] - '0');
    int mx = (lim  ? 9 : r[cur] - '0');
    ret =0 ;
    if (cur % 2 )
    {
        if (d >= mn && d <= mx )
            ret = solve( cur + 1, (prd * 10 + d )%m, (lim | (d < mx )) , (lim1 | (d > mn )))%M ;
        return ret ;
    }
    for (int i =mn ; i <= mx ; i++)
    {
        if (i == d )continue ;
        ret += solve( cur + 1, (prd * 10 +  i)%m, (lim | (i < mx )) , (lim1 | (i > mn ))) % M ;
        ret %= M;
    }
    return ret ;
}
int main ()
{
    cin >> m >> d >> l >> r ;
    n = SZ(l);
    memset( dp, -1,sizeof dp );
    cout << solve() <<"\n";
    return 0;
}