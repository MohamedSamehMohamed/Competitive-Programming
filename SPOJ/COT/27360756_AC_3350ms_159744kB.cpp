// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e6+9, Lg = 20;
struct node;
extern node* empty;
struct node
{
  node *l, *r;
  int frq;
  node()
  {
    frq = 0;
    l = r = this;
  }
  node(int frq, node *l, node *r)
  {
    this->frq = frq;
    this->l = l;
    this->r = r;
  }
};
node *empty = new node;
int tour[N], idx, in[N], lvl[N], a[N], par[N], spt[N][Lg], Log[N], n, m;
node *roots[N];
vector<int> adj[N];
node *insert(node *root, int val, int nst = INT_MIN, int nen = INT_MAX)
{
  if (val < nst || val > nen)return root;
  if (nst == nen)return new node(root->frq + 1, root->l, root->r);
  int m = (0LL+nst + nen) >> 1;
  node *nl = insert(root->l, val, nst, m);
  node *nr = insert(root->r, val, m+1, nen);
  return new node(nl->frq + nr->frq, nl, nr);
}
int query(node *ra, node *rb, node *rc, node *rd, int k, int nst = INT_MIN, int nen = INT_MAX)
{
  if (nst == nen)return nst;
  int lsz = ra->l->frq + rb->l->frq - rc->l->frq - rd->l->frq;
  int m = (0LL+nst+nen)>>1;
  if (lsz >= k)
    return query(ra->l, rb->l, rc->l, rd->l, k, nst, m);
  return query(ra->r, rb->r, rc->r, rd->r, k-lsz, m+1, nen);
}
void dfs(int u = 1, int p = 0)
{
  lvl[u] = lvl[p] + 1;
  par[u] = p;
  in[u] = idx;
  tour[idx] = u;
  idx++;
  roots[u] = insert(roots[p], a[u]);
  for (int i: adj[u])
    if (i != p)
    {
      dfs(i, u);
      tour[idx] = u;
      idx++;
    }
}
void buildSpt()
{
  for (int i = 2; i < N; i++)Log[i] = Log[i>>1] + 1;
  for (int i = 0; i < idx; i++)spt[i][0] = i;
  for (int j = 1; j < Lg; j++)
    for (int i = 0; i + (1<<j) <= idx; i++)
      {
        int l = spt[i][j-1];
        int r = spt[i+(1<<(j-1))][j-1];
        spt[i][j] = lvl[tour[l]] < lvl[tour[r]] ? l: r;
      }
}
int min_query(int u, int v)
{
  int sz = Log[v - u + 1];
  int l = spt[u][sz];
  int r = spt[v-(1<<sz)+1][sz];
  return lvl[tour[l]] < lvl[tour[r]]? l: r;
}
int lca(int u, int v)
{
  u = in[u];
  v = in[v];
  if (u > v)swap(u, v);
  return tour[min_query(u, v)];
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)scanf("%d", a+i);
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  roots[0] = empty;
  dfs();
  buildSpt();
  while(m--)
  {
    int u, v, k;
    scanf("%d%d%d", &u, &v, &k);
    int lc = lca(u, v);
    printf("%d\n", query(roots[u], roots[v], roots[lc], roots[par[lc]], k));
  }
}
