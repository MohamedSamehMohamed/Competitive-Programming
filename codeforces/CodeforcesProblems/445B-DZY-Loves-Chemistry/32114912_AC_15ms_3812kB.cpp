#include<bits/stdc++.h>
using namespace std;
const int N = 51;
int n, m, cnt, vis[N];
vector<int> adj[N];
void dfs(int u)
{
    if (vis[u])return;
    vis[u] = 1;
    cnt++;
    for(int v: adj[u])
        dfs(v);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt = -1;
            dfs(i);
            while(cnt--)
                ans *= 2;
        }
    }
    printf("%lld\n", ans);
}