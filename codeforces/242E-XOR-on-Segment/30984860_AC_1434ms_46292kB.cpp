#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 20, M = 25;
int a[N], n, m;
vector<int> seg[N];
int lazy[N];
void XorNode(vector<int> &v, int sz, int msk)
{
  for (int i = 0; i < M; i++)
    if (msk & (1<<i))
      v[i] = sz - v[i];
}
void push_down(int node, int l, int r)
{
  if (lazy[node] == 0)return;
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  int lsz = m - l + 1;
  int rsz = r - m;
  XorNode(seg[n1], lsz, lazy[node]);
  XorNode(seg[n2], rsz, lazy[node]);
  lazy[n1] ^= lazy[node];
  lazy[n2] ^= lazy[node];
  lazy[node] = 0;
}
vector<int> merge(vector<int> l, vector<int> r)
{
  vector<int> ret(M, 0);
  for (int i = 0; i < M; i++)
    ret[i] = l[i] + r[i];
  return ret;
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = vector<int>(M, 0);
    for (int i = 0; i < M; i++)
      if (a[l] & (1<<i))
        seg[node][i]++;
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
void updateRange(int le, int re, int val, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return;
  if (l >= le && r <= re)
  {
    int sz = r - l + 1;
    int msk = 0;
    for (int i = 0; i < M; i++)
      if (val & (1<<i))
      {
        msk |= 1<<i;
        seg[node][i] = sz - seg[node][i];
      }
    lazy[node] ^= msk;
    return;
  }
  push_down(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  updateRange(le, re, val, n1, l, m);
  updateRange(le, re, val, n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
long long query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return 0;
  if (l >= le && r <= re)
  {
    long long ret = 0;
    long long cur = 1;
    for (int i = 0; i < M; i++, cur *= 2)
    {
      int rep = seg[node][i];
      while(rep--)
        ret += cur;
    }
    return ret;
  }
  push_down(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  scanf("%d", &m);
  while(m--)
  {
    int ty, l, r, val;
    scanf("%d%d%d", &ty, &l, &r);
    l--;r--;
    if (ty == 1)
      printf("%lld\n", query(l, r));
    else
    {
      scanf("%d", &val);
      updateRange(l, r, val);
    }
  }
}
