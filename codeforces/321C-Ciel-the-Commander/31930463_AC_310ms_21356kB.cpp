#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m;
vector<int> adj[N], g[N];
int subSize[N];
int par[N], ans[N];
bool vis[N];
void dfs(int u = 0, int p = 0)
{
    subSize[u] = 1;
    par[u] = p;
    for(int v: adj[u])
    {
        if (v != p && !vis[v])
        {
            dfs(v, u);
            subSize[u] += subSize[v];
        }
    }
}
int get_centroid(int u, int p, int sz)
{
    for(int v: adj[u])
    {
        if (v != p && !vis[v])
        {
            if (2 * subSize[v] > sz)
                return get_centroid(v, u, sz);
        }
    }
    return u;
}
void dfs2(int u, int p)
{
    par[u] = p;
    for(int v: g[u])
        if (v != p)
            dfs2(v, u);
}
int Rank[N];
int decompose(int u = 0)
{
    dfs(u, u);
    int centroid = get_centroid(u, u, subSize[u]);
 
    vis[centroid] = 1;
    for(int v: adj[centroid])
        if (!vis[v])
        {
            int u = decompose(v);
            g[centroid].push_back(u);
            g[u].push_back(centroid);
        }
    return centroid;
}
 
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = decompose();
    dfs2(root, root);
    Rank[root] = 0;
    queue<int> q;
    q.push(root);
    bool can = 1;
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        for(int v: g[root])
        {
            if (v == par[root])continue;
            Rank[v] = Rank[root] + 1;
            if (Rank[v] > 25)can = 0;
            q.push(v);
        }
    }
    if (!can)
    {
        printf("Impossible!\n");
    }else
    {
        for(int i = 0; i < n; i++)
            printf("%c ", Rank[i] + 'A');
        printf("\n");
    }
 
}