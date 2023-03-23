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
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std ;
const int N = 1 << 20;
int n, q, a[N];
struct Node{
  int pref, suf, ans, left, right;
  Node()
  {
    pref = suf = ans = left = right = 0;
  }
  void set(int pref, int suf, int ans, int left, int right)
  {
    this->pref = pref;
    this->suf  = suf;
    this->ans  = ans;
    this->left = left;
    this->right = right;
  }
  void cal(Node ln, Node rn)
  {
    pref = (ln.left == rn.left? ln.pref + rn.pref: ln.pref);
    suf  = (ln.right == rn.right? ln.suf + rn.suf: rn.suf);
    int jointSegment = (ln.right == rn.left? ln.suf + rn.pref: 0);
    ans = max({jointSegment, ln.ans, rn.ans});
    left = ln.left;
    right = rn.right;
  }
}seg[N];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].set(1, 1, 1, a[l], a[l]);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  build(n1, l, m);
  build(n1+1, m+1, r);
  seg[node].cal(seg[n1], seg[n1+1]);
}
Node query(int l, int r, int node = 0, int nst = 0, int nen = n-1)
{
  if (nst == l && nen == r)return seg[node];
  int m = (nst+nen)>>1;
  int n1 = node * 2 + 1;
  if (r <=m)return query(l, r, n1, nst, m);
  if (l > m)return query(l, r, n1+1, m+1, nen);
  Node com;
  Node le = query(l, m, n1, nst, m);
  Node re = query(m+1, r, n1+1, m+1, nen);
  com.cal(le, re);
  return com;
}
int main()
{
  while(scanf("%d", &n) && n && scanf("%d", &q))
  {
    for (int i = 0; i < n; i++)scanf("%d", a+i);
    build();
    while(q--)
    {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", query(l-1, r-1).ans);
    }
  }
}
