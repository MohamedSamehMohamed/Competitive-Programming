const int N = 1e5 + 9;
int par[N], n;
int get_par(int u)
{
    return u == par[u]? u: par[u] = get_par(par[u]);
}
bool uni(int u, int v)
{
    u = get_par(u);
    v = get_par(v);
    if (u == v)return 0;
    par[u] = v;
    return 1;
}
iota(par, par + n, 0);