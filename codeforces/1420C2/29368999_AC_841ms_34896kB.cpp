// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
struct Node{
  long long pp, pm, mm, mp;
  Node(){}
  Node(int x)
  {
    pp = x;
    pm = 0;
    mp = 0;
    mm = -x;
  };
  long long ans()
  {
    return max(pp, pm);
  }
};
const int N = 1 << 19;
int a[N], n, q;
Node seg[N<<1];
Node merge(Node l, Node r)
{
  Node ret;
  ret.pp = max(l.pp + r.mp, l.pm + r.pp);
  ret.pm = max(l.pm + r.pm, l.pp + r.mm);
  ret.mp = max(l.mp + r.mp, l.mm + r.pp);
  ret.mm = max(l.mm + r.pm, l.mp + r.mm);
  return ret;
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = Node(a[l]);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
void update(int pos, int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > pos || r < pos)return;
  if (l == r)
  {
    seg[node] = Node(val);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(pos, val, n1, l, m);
  update(pos, val, n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
void test()
{
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  printf("%lld\n", seg[0].ans());
  while(q--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;r--;
    swap(a[l], a[r]);
    update(l, a[l]);
    update(r, a[r]);
    // printT();
    printf("%lld\n", seg[0].ans());
  }
}
int main()
{
  int t; scanf("%d", &t);
  while(t--)
    test();
}
