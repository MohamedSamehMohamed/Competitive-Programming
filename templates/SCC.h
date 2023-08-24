vector<int> adj[N], adj_rev[N], order, component;
int used[N];
void dfs1(int v) {
    used[v] = true;
    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}
void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}
void SplitComponent()
{
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    memset(used, 0, sizeof used);
    reverse(order.begin(), order.end());
    for (auto v : order)
    {
        if (used[v])continue;
        dfs2(v);
        // component contain cur SCC
        component.clear();
    }
}