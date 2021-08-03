// problemLink: https://codeforces.com/contest/277/problem/A
#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 109;
int n, m;
vector<int> adj[N];
bool vis[N];
void dfs(int u)
{
    if (vis[u])return;
    vis[u] = 1;
    for(int v: adj[u])
        dfs(v);
}
int main()
{
    scanf("%d%d", &n, &m);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int lang;
        scanf("%d", &lang);
        if (lang != 0)ans = -1;
        while(lang--)
        {
            int v;
            scanf("%d", &v);
            v--;
            adj[i].push_back(v + n);
            adj[v+n].push_back(i);
        }
    }
    for(int i = 0; i < n; i++)
        if (!vis[i])
        {
            dfs(i);
            ans++;
        }
    printf("%d\n", ans);
}
