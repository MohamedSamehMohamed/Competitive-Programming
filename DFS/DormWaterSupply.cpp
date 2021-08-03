// problemLink: https://codeforces.com/contest/107/problem/A
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
vector<pair<int, int>> adj[N];
bool In[N], vis[N];
int n, m, start;
vector<array<int, 3>> ans;
void dfs(int u, int w = 1e9)
{
    if (vis[u])return;
    if (adj[u].size() == 0)
    {
        if (start != u)
            ans.push_back({1 + start, 1 + u, w});
        return;
    }
    vis[u] = 1;
    dfs(adj[u][0].first, min(w, adj[u][0].second));
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--;v--;
        adj[u].push_back({v, w});
        In[v] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        if (!In[i])
        {
            start = i;
            dfs(i);
        }
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        for(int j = 0; j < 3; j++)
            printf("%d%c",  ans[i][j], (j == 2? '\n': ' '));
}
