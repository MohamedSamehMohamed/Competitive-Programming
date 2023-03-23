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
const int M = 1e5 + 1 ;
int par[M];
int getpar(int u )
{
    if (u != par[u])return par[u] = getpar(par[u]);
    return u ;
}
bool conect (int u , int v )
{
    u = getpar(u);
    v = getpar(v);
    if ( u == v )return 1 ;
    par[u] = v ;
    return 0 ;
}
int main()
{
    int x ,y ;
    while (scanf ("%d" , &x ))
    {
        if (x == -1 )break;
        int ans =0 ;
        for (int i =0 ; i < M ;i++)par[i] = i ;
        scanf ("%d" , &y );
        ans += conect(x , y );
        while (1)
        {
            scanf ("%d" , &x );
            if ( x == -1 )break;
            scanf ("%d" , &y );
            ans += conect(x , y );
        }
        printf ("%d\n" ,ans );
    }
}
