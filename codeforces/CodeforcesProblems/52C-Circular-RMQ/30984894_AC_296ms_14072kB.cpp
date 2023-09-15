// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 18;
int n, q;
long long a[N], seg[N<<1], lazy[N<<1];
char line[30];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = a[l];
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = min(seg[n1], seg[n2]);
}
void LazyUpdate(int node)
{
  if (lazy[node])
  {
    seg[node*2+1] += lazy[node];
    seg[node*2+2] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node*2+2] += lazy[node];
    lazy[node] = 0;
  }
}
long long query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node];
  LazyUpdate(node);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return min(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
}
void update(int le, int re, int value, int node = 0, int l = 0, int r = n-1)
{
  if (l > re || r < le) return;
  if (l >= le && r <= re)
  {
    seg[node] += value;
    lazy[node] += value;
    return;
  }
  LazyUpdate(node);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, value, n1, l, m);
  update(le, re, value, n2, m+1, r);
  seg[node] = min(seg[n1], seg[n2]);
}
long long queryHelper(int l, int r)
{
  if (l <= r)
    return query(l, r);
  return min(query(l, n-1), query(0, r));
}
void updateHelper(int l, int r, int value)
{
  if (l <= r)
  {
    update(l, r, value);
  }else
  {
    update(l, n-1, value);
    update(0, r, value);
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lld", a+i);
  build();
  scanf("%d", &q);
  gets(line);
  while(q--)
  {
    int l, r, v;
    while(gets(line) == NULL);
    if (sscanf(line, "%d%d%d", &l, &r, &v) == 3)
      updateHelper(l, r, v);
    else
      printf("%lld\n", queryHelper(l, r));
  }
}