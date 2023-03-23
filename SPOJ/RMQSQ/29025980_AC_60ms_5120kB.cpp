// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 17;
int a[N], seg[N<<1], n, q;
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
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node];
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return min(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  scanf("%d", &q);
  while(q--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query(l, r)); 
  }
}
