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
  for (int i = 0; i < n; i++)
    if (a[i] > 0)
      vec[a[i]].push_back(i);
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < 0)continue;
    int l = 0, r = n-1;
    for (int cur = a[i]+1; cur <= 30; cur++)
    {
      if (vec[cur].empty())continue;
      if (vec[cur].size() == 1)
      {
        if (vec[cur][0] > i)
          r = min(r, vec[cur][0]-1);
        else
          l = max(l, vec[cur][0]+1);
      }else
      {
        int nxt = lower_bound(vec[cur].begin(), vec[cur].end(), i) - vec[cur].begin();
        int prv = nxt-1;
        l = max(l, vec[cur][prv]+1);
        r = min(r, vec[cur][nxt]-1);
      }
    }
    if (l <= r)
      ans = max(ans, query(l, r).ans - a[i]);
  }
  printf("%d\n", ans);

}
