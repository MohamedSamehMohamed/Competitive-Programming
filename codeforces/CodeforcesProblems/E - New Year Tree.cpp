#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int st[N], en[N], tour[N], ti, n, m; 
vector<int> adj[N];
long long seg[4*N], lazy[4*N], colr[N]; 
void push_down(int node)
{
 if (lazy[node])
 {
  int n1 = node * 2 + 1;
  int n2 = n1 + 1; 
  seg[n1] = lazy[node];
  seg[n2] = lazy[node];
  lazy[n1] = lazy[n2] = lazy[node];
  lazy[node] = 0; 
 }
}
void build(int node = 0, int l = 0, int r = ti-1)
{
  if (l == r)
  {
   seg[node] = colr[tour[l]]; 
   return; 
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = seg[n1] | seg[n2];  
}
void update(int le, int re, long long val, int node = 0, int l = 0, int r = ti-1)
{
 if (l > re || r < le)
  return; 
 if (l >= le && r <= re)
 {
  seg[node] = val;
  lazy[node] = val; 
  return; 
 }
 push_down(node); 
 int m = (l+r)>>1;
 int n1 = node * 2 + 1; 
 int n2 = n1 + 1; 
 update(le, re, val, n1, l, m);
 update(le, re, val, n2, m+1, r);
 seg[node] = seg[n1] | seg[n2]; 
}
long long query(int le, int re, int node = 0, int l = 0, int r = ti-1)
{
 if (l > re || r < le)
  return 0; 
 if (l >= le && r <= re)
  return seg[node]; 
 push_down(node);
 int m = (l+r)>>1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 return query(le, re, n1, l, m) | query(le, re, n2, m+1, r); 
}
void dfs(int u = 0, int p = -1)
{
  st[u] = ti;
  tour[ti++] = u; 
  for (int i: adj[u])
   if (i != p)
    dfs(i, u); 
  en[u] = ti; 
  tour[ti++] = u;  
}
pair<int, int> get_range(int u)
{
 return {st[u], en[u]}; 
}
int count(long long x)
{
 int cnt = 0;
 while(x)
 {
  cnt += (x&1); 
  x >>= 1LL; 
 }
 return cnt; 
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
   scanf("%lld", colr+i), colr[i] = (1LL<<colr[i]); 
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  dfs(); 
  build();
  while(m--)
  {
   int ty, v, c; 
   scanf("%d%d", &ty, &v);
   v--;
   auto rng = get_range(v);
   if (ty == 1)
   {
    scanf("%d", &c); 
    update(rng.first, rng.second, 1LL<<c); 
   }
   else 
   {
    printf("%d\n", count(query(rng.first, rng.second)));
   }
  }
}
