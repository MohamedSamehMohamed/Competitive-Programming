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
vector <int> adj[202];
bool vis[202];
void dfs (int u )
{
    vis[u] =1;
    for (auto v : adj[u])
    {
        if (vis[v])continue ;
        dfs(v);
    }
}
int main()
{
    int n , m;
    scanf ("%d%d" , &n ,&m );
    int extra =0 ;
    for (int i =0 ; i < n ;i++)
    {
        int k ;
        scanf ("%d" , &k );
        extra += !k ;
        if (!k)vis[i]=1;
        while (k--)
        {
            int lag ;
            scanf ("%d" ,&lag );
            lag+=100;
            adj[i].pb(lag);
            adj[lag].pb(i);
        }
    }
    int ans =-1 ;
    for (int i =0 ; i < n ;i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ans++;
        }
    }
    if (ans == -1 )ans =0 ;
    printf ("%d\n" ,ans+extra );


}
