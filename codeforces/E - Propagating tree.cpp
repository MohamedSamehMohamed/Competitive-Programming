// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
long long seg[8*N], lazy[8*N]; 
int tour[2*N], st[N], en[N], lvl[N], Val[N], ti=0, n, m;
vector<int> adj[N];
void push_down(int node)
{
 if (lazy[node])
 {
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  seg[n1] += lazy[node];
  seg[n2] += lazy[node]; 
  lazy[n1] += lazy[node];
  lazy[n2] += lazy[node];
  lazy[node] = 0;  
 }
}
void update(int le, int re, int val, int node = 0, int l = 0, int r = ti-1)
{
 if (l > re || r < le)return;
 if (l >= le && r <= re)
 {
  seg[node] += val;
  lazy[node] += val; 
  return; 
 }
 push_down(node);
 int m = (l+r) >> 1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1;
 update(le, re, val, n1, l, m);
 update(le, re, val, n2, m+1, r);
 seg[node] = seg[n1] + seg[n2]; 
}
long long query(int pos, int node = 0, int l = 0, int r = ti-1)
{
 if (l > pos || r < pos)return 0;
 if (l == r)return seg[node];
 push_down(node);
 int m = (l+r)>>1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 return query(pos, n1, l, m) + query(pos, n2, m+1, r);
}
void dfs(int u = 0, int p = -1)
{
 lvl[u] = (~p? lvl[p] ^ 1: 0); 
 st[u] = ti; 
 tour[ti++] = u;
 for (int i: adj[u])
  if (i != p)
   dfs(i, u);
 en[u] = ti;
 tour[ti++] = u; 
}
void Tour()
{
 for (int i = 0; i < ti; i++)cout << tour[i]+1 <<" "; cout << "\n";
 for (int i = 0; i < n; i++)cout << st[i] <<" ";cout <<"\n"; 
 for (int i = 0; i < n; i++)cout << en[i] <<" ";cout <<"\n"; 
}
void PrintTree(int node = 0, int l = 0, int r = ti-1)
{
 if (l == r)
 {
  for (int i = l; i <= r; i++)
   cout << tour[i] + 1<<" ";
  cout <<"\n"; 
  cout << l <<" " << r <<" " << seg[node] <<"\n"; 
  return; 
 }
 push_down(node);
 int m = (l+r) >> 1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1;
 PrintTree(n1, l, m);
 PrintTree(n2, m+1, r); 
}
int main()
{
 scanf("%d%d", &n, &m);
 for (int i = 0; i < n; i++)
  scanf("%d", Val+i);
 for (int i = 0; i < n-1; i++)
 {
  int u, v;
  scanf("%d%d", &u, &v);
  u--;v--;
  adj[u].push_back(v);
  adj[v].push_back(u); 
 }
 dfs();
 for (int i = 0; i < n; i++)
  update(st[i], st[i], (lvl[i]? -1 : 1) * Val[i]); 
 while(m--)
 {
  int ty, node, val;
  scanf("%d%d", &ty, &node);
  node--; 
  if (ty == 1)
  {
   scanf("%d", &val);
   if (lvl[node])val *= -1; 
   update(st[node], en[node], val);
  }else 
  {
   printf("%lld\n", query(st[node]) * (lvl[node]? -1: 1)); 
  }
  //PrintTree();
 }
}
