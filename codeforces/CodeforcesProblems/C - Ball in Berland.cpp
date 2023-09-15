// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int n, m, k;
vector<pair<int,int>> v;
vector<int> seg[4 * N];
void merge(int l, int r, int node)
{
  #define all(v) v.begin(),v.end()
  seg[node].clear();
  merge(all(seg[l]), all(seg[r]), inserter(seg[node], seg[node].begin()));
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].clear();
    seg[node].push_back(v[l].second);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  merge(n1, n2, node);
}
int Count(int idx, int val)
{
  int l = 0, r = seg[idx].size()-1, L = 0, R = -1;
  while(l <= r)
  {
    int m = (l+r) >> 1;
    if (seg[idx][m] < val)
      l = m+1;
    else
      r = m-1, L = m;
  }
  if (seg[idx][L] != val)return 0;
  l = L, r = seg[idx].size()-1;
  while(l <= r)
  {
    int m = (l+r) >> 1;
    if (seg[idx][m] > val)
      r = m-1;
    else
      l = m+1, R = m;
  }
  return R - L + 1;
}
int query(int le, int re, int val, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return 0;
  if (l >= le && r <= re)
    return Count(node, val);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return query(le, re, val, n1, l, m) + query(le, re, val, n2, m+1, r);
}
int last(int x)
{
  int l = 0, r = n-1, ans = n;
  while(l <= r)
  {
    int m = (l+r) >> 1;
    if (v[m].first > x)
      r = m-1;
    else
      l = m+1, ans = m+1;
  }
  return ans;
}
void test()
{
  scanf("%d%d%d", &n, &m, &k);
  n = k;
  v.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i].first);
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i].second);
  sort(v.begin(), v.end()); 
  build();
  long long ans = 0;
  for (int i = 0; i + 1 < n; i++)
  {
    int l = last(v[i].first);
    int c = query(l, n-1, v[i].second);
    ans += n - l - c;
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
