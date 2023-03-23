// Author : Mohamed sameh
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std ;
const int N = 1<<18;
vector<int> seg[N<<1];
int n, m, a[N];
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
    return seg[node].size() - (lower_bound(all(seg[node]), k+1) - seg[node].begin());
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, k, n1, l, m);
  if (le > m)
    return query(le, re, k, n2, m+1, r);
  return query(le, re, k, n1, l, m) + query(le, re, k, n2, m+1, r);
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
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--;r--;
    printf("%d\n", query(l, r, k));
  }
}
