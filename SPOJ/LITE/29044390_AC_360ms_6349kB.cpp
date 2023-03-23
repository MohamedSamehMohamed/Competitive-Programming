// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 19;
pair<int,int> seg[N];
int n, q, lazy[N];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].first = 0;
    seg[node].second = 1;
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node].first = seg[n1].first + seg[n2].first;
  seg[node].second = seg[n1].second + seg[n2].second;
}
void pushDown(int node)
{
  if (lazy[node]%2)
  {
    int n1 = node * 2 + 1;
    int n2 = n1 + 1;
    swap(seg[n1].first, seg[n1].second);
    swap(seg[n2].first, seg[n2].second);
    lazy[n1]++;
    lazy[n2]++;
    lazy[node] = 0;
  }
}
void update(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l > re || r < le)
    return;
  if (l >= le && r <= re)
  {
    swap(seg[node].first, seg[node].second);
    lazy[node]++;
    return;
  }
  pushDown(node);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, n1, l, m);
  update(le, re, n2, m+1, r);
  seg[node].first = seg[n1].first + seg[n2].first;
  seg[node].second = seg[n1].second + seg[n2].second;
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node].first;
  pushDown(node);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
int main()
{
  scanf("%d%d", &n, &q);
  build();
  while(q--)
  {
    int ty, l, r;
    scanf("%d%d%d", &ty, &l, &r);
    l--;r--;
    if (ty)
      printf("%d\n", query(l, r));
    else
      update(l, r);
  }
}
