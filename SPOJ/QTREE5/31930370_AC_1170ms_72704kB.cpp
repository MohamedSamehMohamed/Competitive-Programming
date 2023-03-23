#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, Lg = 20;
int n, m;
vector<int> adj[N], g[N];
int subSize[N];
int par[N], ans[N];
bool vis[N];
class LCA
{
    int minD[N], dep[N], tour[2*N], st[N], spt[2*N][Lg], Log[2*N], idx;

    void dfs (int u = 0, int p = 0)
    {
        st[u] = idx ;
        tour[idx++] =u;
        dep[u] = dep[p] + 1;
        for (int i : adj[u])
            if (i != p)
            {
                dfs(i, u);
                tour[idx++] = u;
            }
    }
    void buildSpt()
    {
        for (int i = 2 ;i <= idx ;i++)Log[i] = Log[i/2] + 1;
        for (int i =0 ; i < idx ;i++)spt[i][0] = i;
        for (int j = 1; j < Lg ;j++)
        {
            for (int i =0; i + (1<<j) <= idx ;i++)
            {
                int a = spt[i][j-1];
                int b = spt[i+(1<<(j-1))][j-1];
                spt[i][j] = dep[tour[a]] < dep[tour[b]] ? a : b ;
            }
        }
    }
    int mquery(int l, int r)
    {
        int sz = Log[r - l + 1];
        int a = spt[l][sz];
        int b = spt[r-(1<<sz)+1][sz];
        return dep[ tour[a] ] < dep[ tour[b] ] ? a : b ;
    }
    int lca (int u, int v)
    {
        u = st[u];
        v = st[v];
        if (u > v )swap(u, v);
        return tour[mquery(u, v)];
    }
public:
    void Init()
    {
        dfs();
        buildSpt();
    }
    int dist (int u, int v)
    {
        return dep[u] + dep[v] - 2 * dep[lca(u,v)];
    }


}obj;
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
set<pair<int, int>> nodeMin[N];
int nodeValue(int node)
{
    if (nodeMin[node].empty())
        return 3*N;
    return nodeMin[node].begin()->first;
}
void update(int node)
{
    int root = node;
    bool Set = (nodeValue(node) != 0);
    if(Set)
        nodeMin[node].insert({0, node});
    else
        nodeMin[node].erase({0, node});

    while (node != par[node]) {
        node = par[node];
        if (Set)
            nodeMin[node].insert({obj.dist(root, node), root});
        else
            nodeMin[node].erase({obj.dist(root, node), root});
    }
}
int query(int node)
{
    int root = node;
    int mn = nodeValue(node);
    while(node != par[node])
    {
        node = par[node];
        mn = min(mn, nodeValue(node) + obj.dist(root, node));
    }
    return mn;
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
    scanf("%d", &m);
    obj.Init();
    int root = decompose();
    dfs2(root, root);
    for (int i = 0; i < n; i++)
        ans[i] = 3*N;
    while(m--)
    {
        int ty, v;
        scanf("%d%d", &ty, &v);
        v--;
        if (ty == 0)
        {
            update(v);
        }else
        {
            int ret = query(v);
            if (ret > N)ret = -1;
            printf("%d\n", ret);
        }
    }
}
