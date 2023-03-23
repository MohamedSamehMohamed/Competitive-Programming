// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 18;
int n, q;
long long seg[N<<1], lazy[N<<1];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = 0;
    lazy[node] = 0;
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = seg[n1] + seg[n2];
  lazy[node] = 0;
}
void LazyUpdate(int node, int l, int r)
{
  if (lazy[node])
  {
    int m = (l+r)>>1;
    int lsz = (m-l+1);
    int rsz = (r-m);
    seg[node*2+1] += lazy[node] * lsz;
    seg[node*2+2] += lazy[node] * rsz;
    lazy[node*2+1] += lazy[node];
    lazy[node*2+2] += lazy[node];
    lazy[node] = 0;
  }
}
long long query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node];
  LazyUpdate(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
void update(int le, int re, long long value, int node = 0, int l = 0, int r = n-1)
{
  if (l > re || r < le) return;
  if (l >= le && r <= re)
  {
    seg[node]  += value * (r-l+1);
    lazy[node] += value;
    return;
  }
  LazyUpdate(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, value, n1, l, m);
  update(le, re, value, n2, m+1, r);
  seg[node] = seg[n1] + seg[n2];
}
void test()
{
  scanf("%d%d", &n, &q);
  build();
  while(q--)
  {
    int ty, l, r;
    long long v;
    scanf("%d%d%d", &ty, &l, &r);
    l--;r--;
    if (ty)
      printf("%lld\n", query(l, r));
    else
    {
      scanf("%lld", &v);
      update(l, r, v);
    }
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
