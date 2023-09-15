// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 3e5 + 9;
int q[N], pos[N], n;
int seg[4 * N], lazy[4 * N];
void push(int node)
{
  if (lazy[node])
  {
    int n1 = node * 2 + 1;
    int n2 = n1 + 1;
    seg[n1] += lazy[node];
    seg[n2] += lazy[node];
    lazy[n1] += lazy[node];
    lazy[n2] += lazy[node];
    lazy[node] = 0;
  }
}
void update(int le, int re, int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > re || r < le)return;
  if (l >= le && r <= re)
  {
    seg[node]+= val;
    lazy[node] += val;
    return;
  }
  push(node);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(le, re, val, n1, l, m);
  update(le, re, val, n2, m+1, r);
  seg[node] = max(seg[n1], seg[n2]);
}
int query(int le = 0, int re = n-1, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node];
  push(node);
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)return query(le, re, n1, l, m);
  if (le > m)return query(le, re, n2, m+1, r);
  return max(query(le, re, n1, l, m) , query(le, re, n2, m+1, r));
}
bool bad(int x)
{
  update(0, pos[x], 1);
  if (seg[0] > 0)
  {
    update(0, pos[x], -1);
    return 0;
  }
  return 1;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int x;
    scanf("%d", &x);
    pos[x] = i;
  }
  for (int i = 0; i < n; i++)
    scanf("%d", q+i), q[i]--;
  int ans = n;
  for (int i = 0; i < n-1; i++)
  {
    printf("%d ", ans);
    update(0, q[i], -1);
    while(bad(ans))
      ans--;
  }
  printf("%d\n", ans);
}
