// Author: Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m, m1;
int com1, com2;
int par[2 * N];
int get_par(int u)
{
    return u == par[u]? u: par[u] = get_par(par[u]);
}
bool uni(int u, int v)
{
    u = get_par(u);
    v = get_par(v);
    if (u == v)
        return 1;
    par[u] = v;
    return 0;
}
bool same(int u, int v)
{
    return get_par(u) == get_par(v);
}
int main() {
    scanf("%d%d%d", &n, &m, &m1);
    for(int i = 0; i < 2 * n; i++) {
        par[i] = i;
    }
    com1 = com2 = n;
    for(int i = 0; i < m+m1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        if (i >= m)u+=n, v+=n;
        uni(u, v);
    }
    vector<pair<int, int>> ans;
    for(int i = 1; i < n; i++)
        if (!same(0, i) && !same(n, i+n))
        {
            uni(0, i);
            uni(n, i+n);
            ans.push_back({0, i});
        }
    queue<int> q[2];
    for(int i = 1; i < n; i++)
    {
        if (same(0, i) && !same(n, i+n))
            q[0].push(i);
        else if (!same(0, i) && same(n, i+n))
            q[1].push(i);
    }
    while(!q[0].empty() && !q[1].empty())
    {
        int u = q[0].front();
        int v = q[1].front();

        if (!same(0, u) || same(n, u+n))
        {
            q[0].pop();
            continue;
        }
        if (same(0, v) || !same(n, n+v))
        {
            q[1].pop();
            continue;
        }
        ans.push_back({u, v});
        uni(u, v);
        uni(u+n, v+n);
    }
    printf("%d\n", ans.size());
    for(auto i: ans)
        printf("%d %d\n", i.first + 1, i.second + 1);
}