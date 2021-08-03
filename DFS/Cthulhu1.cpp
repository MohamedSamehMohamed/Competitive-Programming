#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int vis[N], n, m;
vector<int> adj[N];
void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = 1;
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
    int numberOfCom = 0;
    for(int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            numberOfCom++;
            dfs(i);
        }
    }
    if (numberOfCom == 1 && n == m)
        printf("FHTAGN!\n");
    else
        printf("NO\n");
}
