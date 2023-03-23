#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
struct Node
{
  int mx1, mx2;
  Node (){mx1 = mx2 = -1;}
  void init(int x)
  {
    mx1 = x;
    mx2 = -1;
  }
  void update(int x)
  {
    if (x >= mx1)
    {
      mx2 = mx1;
      mx1 = x;
    }else
      mx2 = max(mx2, x);
  }
  int sum()
  {
    return mx1 + mx2;
  }
};
Node merge(Node l, Node r)
{
  int tem[] = {l.mx1, l.mx2, r.mx1, r.mx2};
  sort(tem, tem + 4);
  Node ret;
  ret.mx1 = tem[3];
  ret.mx2 = tem[2];
  return ret;
}
int a[N], n, q;
Node seg[N<<1];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].init(a[l]);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
void update(int pos, int val, int node = 0, int l = 0, int r = n - 1)
{
  if (pos > r || pos < l)return;
  if (l == r)
  {
    seg[node].init(val);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(pos, val, n1, l, m);
  update(pos, val, n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
Node query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return Node();
  if (l >= le && r <= re)
    return seg[node];
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return merge(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
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
    char c;
    int l, r;
    scanf(" %c%d%d", &c, &l, &r);
    if (c == 'Q')
      printf("%d\n", query(--l, --r).sum());
    else
      update(--l, r);
  }
}
