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
const int M = 1e5 + 3 ;
int n , m ;
int x[M] , y[M];
int par[M];
int a[M];
int idx[M];
int getpar(int u )
{
    return ( u != par[u] ? par[u] = getpar(par[u]) : u );
}
void conect (int u , int v )
{
    u = getpar( u );
    v = getpar( v );
    if (u != v )par[u] = v;
}
int main()
{
    scanf ("%d%d" , &n ,&m );
    for (int i =0 ; i < n ;i++)par[i] = i ;
    for (int i =0 ; i< n ;i++)
        scanf ("%d" ,a+ i),idx[ a[i] ] = i ;
    for (int i= 0 ;i < m ; i++)
    {
        scanf ("%d%d" ,x+i , y + i );
        x[i]--;
        y[i]--;
        conect(x[i] , y[i]);
    }
    int ans =0 ;

    for (int i =0 ; i < n ; i++)
    {
       // cout << i <<" " << idx[i+1] <<"\n";
        if (getpar(i) == getpar( idx[i+1] ))
        {
            ans++;
        }
    }
    printf ("%d\n" ,ans );



}
