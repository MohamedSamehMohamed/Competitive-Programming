#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int a[N], n, m;
long long seg[N][2];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node][0] = a[l];
    seg[node][1] = a[l];
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node][0] = seg[n1][0] + seg[n2][0];
  seg[node][1] = max(seg[n1][1], seg[n2][1]);
}
void updateRange(int le, int re, int mod, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return;
  if (seg[node][1] < mod)return;
  if (l == r)
  {
    a[l] %= mod;
    seg[node][0] = a[l];
    seg[node][1] = a[l];
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  updateRange(le, re, mod, n1, l, m);
  updateRange(le, re, mod, n2, m+1, r);
  seg[node][0] = seg[n1][0] + seg[n2][0];
  seg[node][1] = max(seg[n1][1], seg[n2][1]);
}
void update(int pos, int val, int node = 0, int l = 0, int r = n-1)
{
  if (pos > r || pos < l)return;
  if (l == r)
  {
    a[l] = val;
    seg[node][0] = a[l];
    seg[node][1] = a[l];
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(pos, val, n1, l, m);
  update(pos, val, n2, m+1, r);
  seg[node][0] = seg[n1][0] + seg[n2][0];
  seg[node][1] = max(seg[n1][1], seg[n2][1]);
}
long long query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (le > r || re < l)return 0;
  if (l >= le && r <= re)
    return seg[node][0];
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  return query(le, re, n1, l, m) + query(le, re, n2, m+1, r);
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  while(m--)
  {
    int ty, l, r, mod;
    scanf("%d%d%d", &ty, &l, &r);
    l--;r--;
    if (ty == 1)
      printf("%lld\n", query(l, r));
    else if(ty == 2)
    {
      scanf("%d", &mod);
      updateRange(l, r, mod);
    }else
    {
      update(l, r+1);
    }
  }
}
