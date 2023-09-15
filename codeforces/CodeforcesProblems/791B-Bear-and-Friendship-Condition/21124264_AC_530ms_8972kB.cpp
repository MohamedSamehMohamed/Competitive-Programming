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

int n , m ;
vector <int> adj[150000];
bool vis[150000];
int v , e ;
void dfs (int node )
{
    vis[node] = 1;
    e += SZ(adj[node]);
    v++;
    for (int u : adj[node])
        if (!vis[u])dfs(u);
}
int main ()
{
    cin >> n >> m ;
    for (int i =0 ; i < m ;i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i =0 ; i < n ;i++)
    {
        if (!vis[i])
        {
            e = v = 0;
            dfs(i);
            if (e != 1LL * v * (v-1))
            {
                cout <<"NO\n";
                return 0;
            }
        }
    }
    cout <<"YES\n";

     return 0;
}
