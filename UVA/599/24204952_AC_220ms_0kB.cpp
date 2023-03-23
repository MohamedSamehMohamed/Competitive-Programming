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
int t ;
vector<int> adj[26];
bool v[26];
bool vis[26];
int cnt ;
void dfs (int u)
{
    vis[u] = 1;
    cnt++;
    for (int i : adj[u])
    {
        if (vis[i])continue ;
        dfs(i);
    }
}
void solve()
{
    for (int i =0 ; i < 26 ;i++)adj[i].clear();
    memset(vis , 0 ,sizeof vis );
    memset(v , 0 ,sizeof v );
    string x;
    while (cin >> x )
    {
        if (x[0] == '*')break;
        adj[ x[1] - 'A' ].pb( x[3] - 'A' );
        adj[ x[3] - 'A' ].pb( x[1] - 'A' );
    }
    cin >> x ;
    for (int i =0 ; i < SZ(x) ;i+=2)
    {
        v[ x[i] - 'A' ]=1;
    }
    int tree , aco ;
    tree = aco = 0 ;
    for (int i =0 ; i < 26;i++)
    {
        if (!v[i] || vis[i])continue ;
        cnt = 0;
        dfs(i);
        if (cnt == 1 )aco++;
        else
            tree++;
    }
    for (int i = 0 ;i < 26 ;i++)
    {
        if (v[i] && !vis[i])aco++;
    }
    printf("There are %d tree(s) and %d acorn(s).\n" , tree , aco);

}
int main()
{
    cin >> t;
    while (t--)
    {
        solve();
    }

}

