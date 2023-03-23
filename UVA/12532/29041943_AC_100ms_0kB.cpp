// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 18;
int n, q, a[N];
array<int,3> seg[N<<1];
void updateNode(int node, int value)
{
  if (value == 0)
  {
    seg[node][0] = seg[node][1] = 0;
    seg[node][2] = 1;
  }else
  {
    seg[node][0] = (value > 0? 1: 0);
    seg[node][1] = (value < 0? 1: 0);
    seg[node][2] = 0;
  }
}
array<int,3> merge(array<int,3> l, array<int,3> r)
{
  return {l[0]+r[0], l[1]+r[1], l[2]+r[2]};
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    updateNode(node, a[l]);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
void update(int pos, int value, int node = 0, int l = 0, int r = n-1)
{
  if (l > pos || r < pos)
    return;
  if (l == r)
  {
    updateNode(node, value);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(pos, value, n1, l, m);
  update(pos, value, n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
array<int,3> query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node];
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return merge(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
}
char queryHelper(int l, int r)
{
  auto ret = query(l, r);
  if (ret[2])
    return '0';
  return (ret[1] % 2? '-' : '+');
}
int main()
{
  while(~scanf("%d%d", &n, &q))
  {
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    build();
    while(q--)
    {
      char c; int l, r;
      scanf(" %c%d%d", &c, &l, &r);
      l--;
      if (c == 'P')
      {
        printf("%c", queryHelper(l, r-1));
      }else
      {
        update(l, r);
      }
    }
    printf("\n");
  }
}
