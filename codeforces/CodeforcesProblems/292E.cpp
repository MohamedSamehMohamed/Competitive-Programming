#include<bits/stdc++.h>
using namespace std;
const int N = 1<<19;
struct Node{
  int val, st, sz;
  Node(){}
  Node(int x)
  {
    val = x;
    st = -1;
  }
  void add(int start, int len)
  {
    if (len == 0)return;
    if (st == -1)
    {
      st = start;
      sz = len;
    }else
    {
      // not same
      st = start;
      sz = len;
    }
  }
};
Node merge(Node &l, Node &r)
{
  Node ret;
  ret.st = -1;
  return ret;
}
int a[N], b[N], n, q;
Node seg[N<<1];
void push_down(int node, int l, int r)
{
  if (seg[node].st == -1)return;
  if (l == r)
  {
    seg[node].val = a[st];
    st = -1;
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  int szleft = min(m-l+1, seg[node].sz);
  int szright = min(r-m, seg[node].sz - szleft);
  seg[n1].add(seg[node].st, szleft);
  seg[n2].add(seg[node].st+szleft-1, szright);
  seg[node].st = -1;
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = Node(b[l]);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
void update(int le, int re, int val, int sz, int node = 0, int l = 0, int r = n - 1)
{
  if (le > r || re < l)return;
  push_down(node, l, r);
  if (l >= le && r <= re)
  {
    seg[node].st = val;
    seg[node].sz = sz;
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, val, sz,n1, l, m);
  update(le, re, val, sz,n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
long long query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return 0;
  push_down(node, l, r);
  if (l >= le && r <= re)
    return seg[node].val;
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
int main()
{
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  build();
  while(q--)
  {
    int type, x, y, k;
    scanf("%d", &type);
    if (type == 1)
    {
      scanf("%d%d%d", &x, &y, &k);
      y--;x--;
      update(y, y + k -1, x);
    }
  }

}
