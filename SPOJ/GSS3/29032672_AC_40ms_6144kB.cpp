// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
struct Node
{
  int pre, suf, ans, sum;
  Node(){}
  Node(int value)
  {
    pre = suf = ans = sum = value;
  }
};
Node Merge(Node l, Node r)
{
  Node ret;
  ret.pre = max(l.pre, l.sum + r.pre);
  ret.suf = max(r.suf, r.sum + l.suf);
  ret.sum = l.sum + r.sum;
  ret.ans = max({l.ans, r.ans, l.suf + r.pre});
  return ret;
}
const int N = 1 << 16;
int a[N], n, q;
Node seg[N<<1];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = Node(a[l]);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = Merge(seg[n1], seg[n2]);
}
Node query(int le, int re, int node = 0, int l = 0, int r = n-1)
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
  return Merge(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
}
void update(int pos, int value, int node = 0, int l = 0, int r = n-1)
{
  if (l > pos || r < pos)
    return;
  if (l == r)
  {
    seg[node] = Node(value);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(pos, value, n1, l, m);
  update(pos, value, n2, m+1, r);
  seg[node] = Merge(seg[n1], seg[n2]);
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
    int ty, l, r;
    scanf("%d%d%d", &ty, &l, &r);
    if (ty)
      printf("%d\n", query(l-1, r-1).ans);
    else
      update(l-1, r);
  }
}
