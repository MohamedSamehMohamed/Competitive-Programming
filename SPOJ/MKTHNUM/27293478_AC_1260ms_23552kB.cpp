// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1<<17;
int a[N], n, q;
vector<int> seg[N<<1];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].pb(a[l]);
    return;
  }
  int m = (l+r)>>1;
  int node1 = node*2 + 1;
  int node2 = node1  + 1;
  build(node1, l, m);
  build(node2, m+1, r);
  merge(all(seg[node1]), all(seg[node2]), inserter(seg[node], seg[node].begin()));
}
int lq, rq, val;
int query(int node = 0, int l = 0, int r = n-1)
{
  if (l >= lq && r <= rq)
  {
    return lower_bound(all(seg[node]), val) - seg[node].begin();
  }
  int m = (l+r)>>1;
  int node1 = node*2 + 1;
  int node2 = node1 + 1;
  if (rq <= m)return query(node1, l, m);
  if (lq > m)return query(node2, m+1, r);
  return query(node1, l, m) + query(node2, m+1, r);
}
int main()
{
    scanf("%d", &n);
    scanf("%d", &q);
    for (int i =0 ; i < n ;i++)scanf("%d", a+i);
    build();
    while(q--)
    {
      int k;
      scanf("%d%d%d", &lq, &rq, &k);
      lq--;rq--;k--;
      int l = -1e9, r = 1e9, ans;
      while (l <= r)
      {
        val = (l+r)>>1;
        int ret = query();
        if (ret <= k)
        {
          ans = val;
          l = val+1;
        }else
        r = val-1;
      }
      printf("%d\n", ans);
    }

}
