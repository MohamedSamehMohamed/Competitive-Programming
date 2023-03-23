// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21;
char str[N], x[55];
int n, m, len, q;
pair<int,int> seg[N<<1];
stack<int> lazy[N<<1];
void clear(int node)
{
  while(!lazy[node].empty())
    lazy[node].pop();
}
void updateNode(int node, char c)
{
  seg[node].first = seg[node].second = 0;
  if (c == '1')
    seg[node].first++;
  else
    seg[node].second++;
  clear(node);
}
pair<int,int> merge(pair<int,int> l, pair<int,int> r)
{
  return {l.first + r.first, l.second + r.second};
}
void inverse(int node)
{
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  swap(seg[n1].first, seg[n1].second);
  swap(seg[n2].first, seg[n2].second);
  lazy[n1].push(3);
  lazy[n2].push(3);
}
void change(int node, int l, int r, int val)
{
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  seg[n1].first = (m-l+1);
  seg[n1].second = 0;
  seg[n2].first = r-m;
  seg[n2].second = 0;
  if (val == 2)
  {
    swap(seg[n1].first, seg[n1].second);
    swap(seg[n2].first, seg[n2].second);
  }
  lazy[n1].push(val);
  lazy[n2].push(val);
}
void pushDown(int node, int l, int r)
{
  int cnt = 0;
  while(!lazy[node].empty())
  {
    int val = lazy[node].top();
    lazy[node].pop();
    if (val != 3)
    {
      change(node, l, r, val);
      clear(node);
      if (cnt)
      {
        inverse(node);
        return;
      }
    }else
    {
      cnt ^= 1;
    }
  }
  if (cnt)
    inverse(node);
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    updateNode(node, str[l]);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
  clear(node);
}
// 1 convert to 1
// 2 convert to 0
// 3 inverse
void update(int le, int re, int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > re || r < le)
    return;
  if (l >= le && r <= re)
  {
    if (val != 3)
    {
      seg[node].first  = (r-l+1);
      seg[node].second = 0;
      if (val == 2)
        swap(seg[node].first, seg[node].second);
      lazy[node].push(val);
    }else
    {
      swap(seg[node].first, seg[node].second);
      lazy[node].push(val);
    }
    return;
  }
  pushDown(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, val, n1, l, m);
  update(le, re, val, n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node].first;
  pushDown(node, l, r);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
void Add()
{
  int sz = strlen(x);
  for (int i = 0; i < sz; i++)
    str[n++] = x[i];
}
void test()
{
  n = 0;
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    int len;
    scanf("%d %s", &len, x);
    while(len--)
      Add();
  }
  build();
  scanf("%d", &q);
  int qq = 1;
  while(q--)
  {
    char c;
    int l, r;
    scanf(" %c%d%d", &c, &l, &r);
    if (c == 'F')
      update(l, r, 1);
    else if (c == 'E')
      update(l, r, 2);
    else if (c == 'I')
      update(l, r, 3);
    else
      printf("Q%d: %d\n", qq++, query(l, r));
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    printf("Case %d:\n", i+1);
    test();
  }
}
