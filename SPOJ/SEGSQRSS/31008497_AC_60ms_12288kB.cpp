#include<bits/stdc++.h>
using namespace std;
/*
a b c
a*a + b*b + c*c

add x:

(a+x)*(a+x) + (b+x)*(b+x) + (c+x)*(c+x)
a*a + x*x + 2xa
b*b + x*x + 2xb
c*c + x*x + 2xc

2xa + 2xb + 2xc = 2x*(a+b+c)

a*a + b*b + c*c + (r-l+1)*x*x + 2*x*(a+b+c)
*/
const int N = 1<<19;
struct Node{
  int sum, lazy;
  long long sumSquare;
  bool isSet;
  Node(){}
  Node(int x)
  {
    sum = x;
    sumSquare = 1LL * x * x;
    isSet = lazy = 0;
  }
  void increment(int val, int sz)
  {
    sumSquare += 1LL * sz * val * val + 2LL * val * sum;
    sum += val * sz;
  }
  void set(int val, int sz)
  {
    sum = sz * val;
    sumSquare = 1LL * val * val * sz;
  }
};
Node merge(Node &l, Node &r)
{
  Node ret;
  ret.sum = l.sum + r.sum;
  ret.sumSquare = l.sumSquare + r.sumSquare;
  ret.lazy = ret.isSet = 0;
  return ret;
}
int a[N], n, q;
Node seg[N<<1];
void push_down(int node, int l, int r)
{
  if (seg[node].lazy == 0 || l == r)return;
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (seg[node].isSet)
  {
    seg[n1].set(seg[node].lazy, m - l + 1);
    seg[n2].set(seg[node].lazy, r - m);
    seg[n1].lazy = seg[n2].lazy = seg[node].lazy;
    seg[n1].isSet = seg[n2].isSet = 1;
  }else
  {
    seg[n1].increment(seg[node].lazy, m - l + 1);
    seg[n2].increment(seg[node].lazy, r - m);
    seg[n1].lazy += seg[node].lazy;
    seg[n2].lazy += seg[node].lazy;
  }
  seg[node].lazy = 0;
  seg[node].isSet = 0;
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
void update(int le, int re, int val, int type, int node = 0, int l = 0, int r = n - 1)
{
  if (le > r || re < l)return;
  push_down(node, l, r);
  if (l >= le && r <= re)
  {
    if (type == 1)
    {
      seg[node].increment(val, r - l + 1);
      seg[node].lazy += val;
    }else
    {
      seg[node].isSet = 1;
      seg[node].lazy = val;
      seg[node].set(val, r - l + 1);
    }
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, val, type,n1, l, m);
  update(le, re, val, type,n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
long long query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return 0;
  push_down(node, l, r);
  if (l >= le && r <= re)
    return seg[node].sumSquare;
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
int Cases;
void test()
{
  printf("Case %d:\n", ++Cases);
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  while(q--)
  {
    int ty, l, r, val;
    scanf("%d%d%d", &ty, &l, &r);
    l--;r--;
    if (ty != 2)scanf("%d", &val);
    switch (ty) {
      case 0:
        update(l, r, val, 2);
      break;
      case 2:
        printf("%lld\n", query(l, r));
      break;
      case 1:
        update(l, r, val, 1);
      break;
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
