// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 14, M = 1e6+9;
int a[N], seg[N<<1], lazy[N<<1], n, q;
bool siev[M];
void PrepareSiev()
{
  siev[0] = siev[1] = 1;
  for (int i = 2; i <= M/i; i++)
  {
    if (siev[i])
      continue;
    for (int j = i * i; j < M; j+=i)
      siev[j] = 1;
  }
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = !siev[a[l]];
    lazy[node] = 0;
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = seg[n1] + seg[n2];
  lazy[node] = 0; 
}
void pushDown(int node, int l, int r)
{
  if (lazy[node])
  {
    int m = (l+r) >> 1;
    int n1 = node * 2 + 1;
    int n2 = n1 + 1;
    seg[n1] = (m-l+1) * (!siev[lazy[node]]);
    seg[n2] = (r-m) * (!siev[lazy[node]]);
    lazy[n1] = lazy[node];
    lazy[n2] = lazy[node];
    lazy[node] = 0;
  }
}
void update(int le, int re, int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > re || r < le)
    return;
  if (l >= le && r <= re)
  {
    seg[node] = (r-l+1) * (!siev[val]);
    lazy[node] = val;
    return;
  }
  pushDown(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, val, n1, l, m);
  update(le, re, val, n2, m+1, r);
  seg[node] = seg[n1] + seg[n2];
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node];
  pushDown(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
void test()
{
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  while(q--)
  {
    int ty, l, r, v;
    scanf("%d%d%d", &ty, &l, &r);
    l--;r--;
    if (ty)
      printf("%d\n", query(l, r));
    else
    {
      scanf("%d", &v);
      update(l, r, v);
    }
  }
}
int main()
{
  PrepareSiev();
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    printf("Case %d:\n", i+1);
    test();
  }
}
