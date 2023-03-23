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
int n , m ;
vector<int> adj[50];
bool vis[50];
int num ;
void dfs (int u )
{
    num++;
    vis[u] = 1;
    for (int j : adj[u])
    {
        if (!vis[j])dfs(j);
    }
}
int main()
{
    scanf ("%d%d" , &n ,&m);
    for (int i =0 ; i < m ;i++)
    {
        int u , v ;
        scanf("%d%d" , &u ,&v);u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = 1 ;
    for (int i =0 ; i < n ; i++)
    {
        if (vis[i])continue ;
        num = 0;
        dfs (i);
        num--;
        while (num--)
        {
            ans *= 2;
        }
    }
    printf ("%lld\n" ,ans );

}