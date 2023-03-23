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
int n , m , l;
const int M = 1e4 ;
vector<int> adj[M];
bool seen[M];
int ans ;
void dfs (int u)
{
    seen[u] = 1;
    for (int i : adj[u])
    {
        if (!seen[i])dfs(i);
    }
}
void solve ()
{
    ans =0 ;
    for (int i =0 ; i < M ;i++)
    {
        seen[i] = 0 ;
        adj[i].clear();
    }
    cin >> n >> m >> l ;
    for (int i =0 ; i < m ;i++)
    {
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    while (l--)
    {
        int z ;
        cin >> z ;
        dfs(z);
    }
    for (int i =0 ; i < M ;i++)ans += seen[i];
    cout << ans <<"\n";

}
int main()
{
    int t;
    cin >> t ;
    while (t--)
    {
        solve();
    }
}
