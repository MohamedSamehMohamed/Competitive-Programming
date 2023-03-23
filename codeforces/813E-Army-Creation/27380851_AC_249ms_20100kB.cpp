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
const int N = 18;
int n, m, k, a[1<<N];
vector<int> seg[1<<N], pos[1<<N];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].pb(a[l]);
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  merge(all(seg[n1]), all(seg[n2]), inserter(seg[node], seg[node].begin()));
}
int query(int node, int l, int r, int lq, int rq, int val)
{
  if (l > rq || r < lq)return 0;
  if (l >= lq && r <= rq)return lower_bound(all(seg[node]), val) - seg[node].begin();
  int m = (l+r)>>1;
  return query(node * 2 + 1, l, m, lq, rq, val) + query(node * 2 + 2, m+1, r, lq, rq, val);
}
int solve(int l, int r)
{
  return query(0, 0, n-1, l, r, l);
}
int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    int x;
    scanf("%d", &x);
    a[i] = (SZ(pos[x]) < k? -1: pos[x][SZ(pos[x])-k]);
    pos[x].pb(i);
  }
  build();
  scanf("%d", &m);
  int l, r, lst = 0;
  while(m--)
  {
    scanf("%d%d", &l, &r);
    l = (lst + l)%n;
    r = (lst + r)%n;
    if (l > r)swap(l, r);
    lst = solve(l, r);
    printf("%d\n", lst);
  }
}
