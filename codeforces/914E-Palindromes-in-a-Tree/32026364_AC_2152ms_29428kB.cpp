#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, K = 20;
int n;
vector<int> adj[N];
int subSize[N];
int par[N];
bool vis[N];
char str[N];
long long  ans[N];
int frq[1<<K];
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
int CountBits(int msk)
{
    int cnt = 0;
    for(int i = 0; i < K; i++)cnt += ((msk & (1<<i)) != 0);
    return cnt;
}
long long calc(int node, int p, int msk)
{
    long long curWays = CountBits(msk) <= 1;

    for(int v: adj[node])
    {
        if (v != p && !vis[v]){
            curWays += calc(v, node, msk ^ (1<<(str[v]-'a')));
        }
    }
    ans[node] += curWays;
    return curWays;
}
void addSubTree(int node, int p, int msk, int val)
{
    frq[msk]+=val;
    for(int v: adj[node])
    {
        if (v != p && !vis[v]){
            addSubTree(v, node,  msk ^ (1<<(str[v]-'a')), val);
        }
    }
}

long long solve(int node, int p, int msk)
{
    long long curWays = frq[msk];
    for(int i = 0; i < K; i++)
    {
        curWays += frq[msk^(1<<i)];
    }
    for(int v: adj[node])
    {
        if (v != p && !vis[v]){
            curWays += solve(v, node,  msk ^ (1<<(str[v]-'a')));
        }
    }
    ans[node] += curWays;
    return curWays;
}
void solve(int root)
{
    int msk = (1 << str[root]-'a');
    // calc for each subtree rooted at root
    calc(root, root, msk);
    // add all subtrees rooted at root
    addSubTree(root, root, msk, 1);
    frq[msk]--;
    long long centriodWays = 0;
    for(int v: adj[root])
    {
        if (!vis[v])
        {
            int nodeMsk = 1<<(str[v]-'a');
            addSubTree(v, root, msk ^ nodeMsk, -1);
            centriodWays += solve(v, root, nodeMsk);
            addSubTree(v, root, msk ^ nodeMsk, 1);
        }
    }
    frq[msk]++;
    addSubTree(root, root, msk, -1);
    ans[root] += centriodWays >> 1;
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
    scanf("%s", str);
    decompose();
    for(int i=0; i < n; i++)
        printf("%lld ", ans[i]);
    printf("\n");
}