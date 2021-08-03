// problemLink: https://codeforces.com/contest/103/problem/B
#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int vis[N], n, m;
vector<int> adj[N];
bool CycleExist(int u, int p)
{
    vis[u] = 1;
    bool cycle = 0;
    for(int v: adj[u])
    {
        if (v == p)continue;
        if (!vis[v])
            cycle |= CycleExist(v, u);
        else
            cycle = 1;
    }
    return cycle;
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
    bool Cycle = 0;
    int numberOfCom = 0;
    for(int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            numberOfCom++;
            Cycle |= CycleExist(i, i);
        }
    }
    if (Cycle && numberOfCom == 1 && n == m)
        printf("FHTAGN!\n");
    else
        printf("NO\n");
}
