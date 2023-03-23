#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, K = 509;
int n, k;
vector<int> adj[N];
int subSize[N];
int par[N], cnt[K];
bool vis[N];
long long total;
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
void calc(int node, int p, int dist)
{
    if (dist > k)
        return;
    total += cnt[k - dist];
    for(int v: adj[node])
    {
        if (v != p && !vis[v])
            calc(v, node, dist + 1);
    }
}
void addSubTree(int node, int p, int dist)
{
    if (dist > k)
        return;
    cnt[dist]++;
    for(int v: adj[node])
    {
        if (v != p && !vis[v])
            addSubTree(v, node, dist + 1);
    }
}
void solve(int root)
{
    memset(cnt, 0, sizeof cnt);
    cnt[0]++;
    for(int v: adj[root])
    {
        if (!vis[v])
        {
            calc(v, root, 1);
            addSubTree(v, root, 1);
        }
    }
}
void decompose(int u = 0)
{
    dfs(u, u);
    int centroid = get_centroid(u, u, subSize[u]);
    vis[centroid] = 1;
    solve(centroid);
    for(int v: adj[centroid])
        if (!vis[v])
            decompose(v);
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose();
    printf("%lld\n", total);
}
