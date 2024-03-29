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
int n ,m,s,ans;
vector<int> adj[5000];
bool vis[5000];
bool vis1[5000];
int un[5000];
priority_queue<pair<int,int>> pq ;
int cnt ;
void dfs1(int u)
{
    vis1[u]=1;
    for (int i : adj[u])
    {
        if (!vis1[i])
        {
            cnt++;
            dfs1(i);
        }
    }
}
void dfs (int u )
{
    vis[u]=1;
    for (int i : adj[u])
    {
        if (!vis[i])
            {
                dfs(i);
                un[u]--;
            }
    }
}
int main()
{
    cin >> n >> m >> s ;
    s--;
    for (int i =0 ; i < m ;i++)
    {
        int u , v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
    }
    dfs(s);
    for (int i =0 ; i < n ;i++)
    {
        if (!vis[i])
        {
            cnt=0;
            memset(vis1, 0,sizeof vis1);
            dfs1(i);
            pq.push({cnt,i});
        }
    }
    while (!pq.empty())
    {
        int cur = pq.top().s ;
        pq.pop();
        if (vis[cur])continue ;
        adj[s].pb(cur);
        dfs(cur);
        ans++;
    }
    cout << ans <<"\n";



}