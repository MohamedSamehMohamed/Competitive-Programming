// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
struct Node
{
  int ans, pre, suf, sum;
  Node(){}
  Node(int val)
  {
    ans = pre = suf = sum = val;
  }
};
Node merge(Node l, Node r)
{
  Node ret;
  ret.pre = max(l.pre, l.sum + r.pre);
  ret.suf = max(r.suf, r.sum + l.suf);
  ret.sum = l.sum + r.sum;
  ret.ans = max({l.ans, r.ans,l.suf+r.pre});
  return ret;
}
const int N = 1 << 17;
int a[N], n;
Node seg[N<<1];
vector<int> vec[31];
int spt[N][17], Log[N];
void buildSparse()
{
  for (int i = 2; i < N; i++)
    Log[i] = Log[i>>1] + 1;
  for (int i = 0; i < n; i++)
    spt[i][0] = a[i];
  for (int j = 1; j < 17; j++)
    for (int i = 0; i + (1<<j) <= n; i++)
      spt[i][j] = max(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
}
int mx(int l, int r)
{
  int sz = Log[r-l+1];
  return max(spt[l][sz], spt[r-(1<<sz)+1][sz]);
}
pair<int, int> BS(int val, int idx)
{
  pair<int, int> rt = {idx, idx};
  int l = 0, r = idx;
  while(l <= r)
  {
    int m = (l+r) >> 1;
    if (mx(m, idx) <= val)
    {
      rt.first = m;
      r = m-1;
    }else
    l = m+1;
  }
  l = idx, r = n-1;
  while(l <= r)
  {
    int m = (l+r) >> 1;
    if (mx(idx, m) <= val)
    {
      rt.second = m;
      l = m+1;
    }else
    r = m-1;
  }
  return rt;
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
Node query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (le > re)return Node(0);
  if (le == l && re == r)return seg[node];
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return merge( query(le, min(re, m), n1, l, m) , query(max(m+1, le), re, n2, m+1, r));
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  buildSparse();
  for (int i = 0; i < n; i++)
    if (a[i] > 0)
      vec[a[i]].push_back(i);
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < 0)continue;
    auto p = BS(a[i], i);
    ans = max(ans, query(p.first, p.second).ans - a[i]);
  }
  printf("%d\n", ans);

}
