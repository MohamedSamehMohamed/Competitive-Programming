#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, Lg = 20;
int n, m;
vector<int> adj[N], Ctree[N];
vector<long long>g[N], gg[N];
int subSize[N];
int par[N], CTPar[N], ans[N];
bool vis[N];
map<pair<int,int>, int> W;
int Wight(int u, int v)
{
    if (u > v)swap(u, v);
    return W[{u, v}];
}
void SetWight(int u, int v, int w)
{
    if (u > v)swap(u, v);
    W[{u, v}] = w;
}
class LCA
{
    int minD[N], tour[2*N], st[N], spt[2*N][Lg], Log[2*N], idx;
    long long dep[N];
    void dfs (int u = 0, int p = 0)
    {
        st[u] = idx ;
        tour[idx++] =u;
        dep[u] = dep[p] + Wight(p, u);
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
    long long dist (int u, int v)
    {
        return dep[u] + dep[v] - 2LL * dep[lca(u,v)];
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
void solve(int p, int u)
{

    for(int v: Ctree[u])
    {
        g[p].push_back(obj.dist(p, v));
        solve(p, v);
    }
}
void solve2(int p, int u, int ch)
{
    for(int v: Ctree[ch])
    {
        gg[p].push_back(obj.dist(u, v));
        solve2(p, u, v);
    }
}
int decompose(int u = 0, int p = -1)
{
    dfs(u, u);
    int centroid = get_centroid(u, u, subSize[u]);
    vis[centroid] = 1;
    CTPar[centroid] = p;
    g[centroid].push_back(0);
    if (~p)
    {
        long long dist = obj.dist(p, centroid);
        gg[centroid].push_back(dist);
    }
    for(int v: adj[centroid])
        if (!vis[v])
        {
            int newCentriod = decompose(v, centroid);
            Ctree[centroid].push_back(newCentriod);

            long long dist = obj.dist(centroid, newCentriod);
            g[centroid].push_back(dist);
            for(int ch: Ctree[newCentriod]){
                g[centroid].push_back(obj.dist(centroid, ch));
                solve(centroid, ch);
            }

            if (~p)
            {
                dist = obj.dist(p, newCentriod);
                gg[centroid].push_back(dist);

                for(int ch: Ctree[newCentriod]) {
                    gg[centroid].push_back(obj.dist(p, ch));
                    solve2(centroid, p, ch);
                }
            }
        }
    return centroid;
}
int query(int node, long long dist)
{
    int root = node;
    int ret = upper_bound(g[node].begin(), g[node].end(), dist) - g[node].begin();
    while(~CTPar[node])
    {
        int p = CTPar[node];
        long long temDist = dist - obj.dist(root, p);
        int add = upper_bound(g[p].begin(), g[p].end(), temDist) - g[p].begin();
        int sub = upper_bound(gg[node].begin(), gg[node].end(), temDist) - gg[node].begin();
        ret += add - sub;
        node = p;
    }
    return ret;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n-1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        SetWight(u, v, w);
    }
    obj.Init();
    decompose();
    for(int i = 0; i < n; i++){
        sort(g[i].begin(), g[i].end());
        sort(gg[i].begin(), gg[i].end());
    }
    while(m--)
    {
        int v;
        long long l;
        scanf("%d%lld", &v, &l);
        v--;
        printf("%d\n", query(v, l));
    }

}
