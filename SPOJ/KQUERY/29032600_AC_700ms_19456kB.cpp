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
const int N = 1<<19;
vector<int> seg[N];
int n, m, a[N];
int l, r, k;
int BS(int idx)
{
  if (SZ(seg[idx]) == 0)return 0;
  int sz = SZ(seg[idx]);
  if (seg[idx][sz-1] <= k)return 0;
  if (seg[idx][0] > k)return sz;
  int lb = 0, rb = sz-1, ans = 0;
  while(lb <= rb)
  {
    int mb = (lb + rb)>>1;
    if (seg[idx][mb] <= k)
    {
      ans = sz - mb-1;
      lb = mb + 1;
    }else rb = mb - 1;
  }
  return ans;
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].pb(a[l]);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  build(node * 2 + 1, l, m);
  build(node * 2 + 2, m+1, r);
  merge(all(seg[n1]), all(seg[n1+1]), inserter(seg[node], seg[node].begin()));
}
int query(int node = 0, int nst = 0, int nen = n-1)
{
  if (nst > r || nen < l)return 0;
  if (nst >= l && nen <= r)return BS(node);
  int m = (nst+nen)>>1;
  return query(node * 2 + 1, nst, m) + query(node * 2 + 2, m+1, nen);
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)scanf("%d", a+i);
  build();
  scanf("%d", &m);
  while(m--)
  {
    scanf("%d%d%d", &l, &r, &k);
    l--;r--;
    printf("%d\n", query());
  }
}
