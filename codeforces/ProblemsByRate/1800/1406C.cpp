// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> adj[N];
int n, sz[N];
int mxSzAfterCut;
int cen1, cen2;
void dfs(int u = 0, int p = -1)
{
    sz[u] = 1;
    int mxSz = -1;
    for(int v: adj[u])
    {
        if (v == p)continue;
        dfs(v, u);
        sz[u] += sz[v];
        mxSz = max(mxSz, sz[v]);
    }
    int mxCom = max(mxSz, n - sz[u]);
    if (mxCom < mxSzAfterCut)
    {
        mxSzAfterCut = mxCom;
        cen1 = u;
        cen2 = -1;
    }else if (mxCom == mxSzAfterCut)
        cen2 = u;
}
void test()
{
    scanf("%d", &n);
    cen1 = cen2 = -1;
    mxSzAfterCut = n;
    for(int i = 0; i < n; i++)
        adj[i].clear();
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    if (cen2 == -1)
    {
        int u = 1;
        int v = adj[0][0]+1;
        printf("%d %d\n%d %d\n", u, v, u, v);
        return;
    }
    int ne = -1;
    for(int v: adj[cen2])
        if (v != cen1)
        {
            ne = v;
            break;
        }
    printf("%d %d\n", ne + 1, cen2 + 1);
    printf("%d %d\n", cen1 + 1, ne + 1);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}