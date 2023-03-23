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
ll a[N];
struct data
{
  ll sum;
  int one;
}seg[4*N];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].sum  = a[l];
    seg[node].one = (a[l] == 1);
    return;
  }
  int m = (l+r)>>1;
  build(node * 2 + 1, l, m);
  build(node * 2 + 2, m+1, r);
  seg[node].sum = seg[node*2+1].sum + seg[node*2+2].sum;
  seg[node].one = seg[node*2+1].one + seg[node*2+2].one;
}
void update(int node = 0, int l = 0, int r = n-1)
{
  if (l > R || r < L)return;
  if (seg[node].one == r - l + 1)return;
  if (l == r)
  {
    seg[node].sum = sqrt(seg[node].sum);
    seg[node].one = (seg[node].sum == 1);
    return;
  }
  int m = (l+r)>>1;
  update(node * 2 + 1, l, m);
  update(node * 2 + 2, m+1, r);
  seg[node].sum = seg[node*2+1].sum + seg[node*2+2].sum;
  seg[node].one = seg[node*2+1].one + seg[node*2+2].one;
}
ll query(int node = 0, int l = 0, int r = n-1)
{
  if (l > R || r < L)return 0;
  if (l >= L && r <= R)return seg[node].sum;
  int m = (l+r)>>1;
  return query(node * 2 + 1, l, m) + query(node * 2 + 2, m+1, r);
}
int main()
{
  int C = 1;
  while(scanf("%d", &n) != EOF){
  printf("Case #%d:\n", C++);
  for (int i = 0; i < n; i++)scanf("%lld", a+i);
  build();
  scanf("%d", &m);
  while(m--)
  {
    int ty;
    scanf("%d%d%d", &ty, &L, &R);
    L--;R--;
    if (L > R)swap(L, R);
    if (ty == 1)
    printf("%lld\n", query());
    else
    update();
  }
  }
}
