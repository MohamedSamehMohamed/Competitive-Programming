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
vector<int> adj[50];
bool vis[50];
int dfs (int node )
{
    int ans =0;
    vis[node]=1;
    for (int i : adj[node])
    {
        if (!vis[i])
            ans += 1 + dfs (i);
    }
    return ans ;
}
int main ()
{
    cin >> n >> m ;
    ll ans =1 ;
    for (int i =0 ; i < m ;i++)
    {
        int u ,v ;
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
            int cur = dfs(i) ;

            ans *= (ll)pow (2LL , cur );
        }
    }
    cout << ans <<"\n";
     return 0;
}
