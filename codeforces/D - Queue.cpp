// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std ;
const int N = 1 << 17;
int a[N], n, q;
vector<int> seg[N<<1];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].push_back(a[l]);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  merge(all(seg[n1]), all(seg[n1+1]), inserter(seg[node], seg[node].begin()));
}
int query(int le, int re, int k, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return (lower_bound(all(seg[node]), k) - seg[node].begin());
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, k, n1, l, m);
  if (le > m)
    return query(le, re, k, n2, m+1, r);
  return query(le, re, k, n1, l, m) + query(le, re, k, n2, m+1, r);
}
void solve(int idx)
{
  int cnt = query(idx, n-1, a[idx]);
  if (cnt <= 0)
  {
    printf("-1 ");
    return;
  }
  int l = 0, r = n - idx - 2, ans = -1;
  while(l <= r)
  {
    int m = (l+r)>>1;
    int ncnt = query(idx+1, idx+1+m, a[idx]);
    if (ncnt >= cnt)
      ans = m, r = m-1;
    else
      l = m+1;
  }
  printf("%d ", ans);
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  for (int i = 0; i < n-1; i++)
    solve(i);
  printf("-1\n");
}
