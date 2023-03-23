// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 4e5+1;
int n, m, L, R;
int a[N];
struct data
{
  ll sum, ans, pre, suf;
  data(int _sum = 0, int _ans = 0, int _pre = 0, int _suf = 0)
  {
    sum = _sum;
    ans = _ans;
    pre = _pre;
    suf = _suf;
  }
}seg[4*N];
data compine(data left, data right)
{
  data ret = data();
  ret.sum = left.sum + right.sum;
  ret.ans = max({ left.sum, right.sum, left.suf + right.pre, left.ans, right.ans});
  ret.pre = max(left.pre, left.sum + right.pre);
  ret.suf = max(right.suf, right.sum + left.suf);
  return ret;
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = data(a[l], a[l], a[l], a[l]);
    return;
  }
  int m = (l+r)>>1;
  build(node * 2 + 1, l, m);
  build(node * 2 + 2, m+1, r);
  seg[node] = compine(seg[node*2+1], seg[node*2+2]);
}
data query(int node = 0, int l = 0, int r = n-1, int le = L, int re = R)
{
  if (l > r || l > re || r < le)return data(-2e12, -2e12, -2e12, -2e12);
  if (l == le && r == re)return seg[node];
  int m = (l+r)>>1;
  return compine(query(node * 2 + 1, l, m, le, min(m,re)), query(node * 2 + 2, m+1, r, max(m+1, le), re));
}
void update(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = data(R, R, R, R);
    return;
  }
  int m = (l+r)>>1;
  if (m >= L)
  update(node * 2+ 1, l, m);
  else
  update(node * 2+ 2, m+1, r);
  seg[node] = compine(seg[node*2+1], seg[node*2+2]);
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)scanf("%d", a+i);
  build();
  scanf("%d", &m);
  while(m--)
  {
    scanf("%d%d", &L, &R);
    L--;R--;
    printf("%lld\n", query().ans);
  }
}
