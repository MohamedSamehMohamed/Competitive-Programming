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
int n ;
const int M = 1e5 + 1;
int frq[M];
int par[M];
int getpar (int u )
{
    if (u != par[u])return par[u] = getpar(par[u]);
    return par[u] ;
}
void mkpar(int u, int v )
{
    u = getpar(u);
    v = getpar(v);
    if (u != v )par[u] = v ;
}
void solve (int T )
{
    scanf ("%d" , &n );
    for (int i = 0 ; i < M ;i++)par[i] = i ,frq[i] = 0;
    for (int i =0 , j ; i < n ;i++)scanf ("%d" ,&j) , frq[j]++;
    ll ans =0 ;
    for (int i = 1; i < M  ;i++)
        if (frq[i])
            ans += 1LL* i * (frq[i] - 1 );

    for (int i = M-1 ; i > 0 ; i--)
    {
        int a = -1 ;
        for (int j = i ; j < M ;j+=i)
        {
            if (!frq[j])continue ;
            if (a == -1 )a = j;
            else
            {
                if (getpar(a) != getpar(j))
                {
                    ans += i ;
                    mkpar(a , j);
                }
            }
        }
    }
    printf ("Case %d: %lld\n" , T , ans );
}
int main()
{
    freopen("dream.in" , "r" , stdin );
    int t ;
    scanf ("%d" , &t ) ;
    for (int i = 1;i <= t ;i++)
    {
        solve(i);
    }

}
