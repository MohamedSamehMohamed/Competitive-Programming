// Author : Mohamed sameh
#include <bits/stdc++.h>
using namespace std ;
int t, n;
vector<array<int, 3>> v;
int seg[1<<20];
void update(int pos, int val, int node = 0, int l = 0, int r = n)
{
  if (l > pos || r < pos)
    return;
  if (l == r)
  {
    seg[node] = min(seg[node], val);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(pos, val, n1, l, m);
  update(pos, val, n2, m+1, r);
  seg[node] = min(seg[n1], seg[n2]);
}
int query(int le, int re, int node = 0, int l = 0, int r = n)
{
  if (l > re || r < le)
    return INT_MAX;
  if (l >= le && r <= re)
    return seg[node];
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return min(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
}
void test()
{
  v.clear();
  fill(seg, seg+(1<<20), INT_MAX);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    v.push_back({a, b, c});
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int mn = query(0, v[i][1]);
    if (mn > v[i][2])
      ans++;
    update(v[i][1], v[i][2]);
  }
  printf("%d\n", ans);
}
int main()
{
  scanf("%d", &t);
  while(t--)
  {
    test();
  }
}
