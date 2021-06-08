// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, q, Q[N][2];
char x[N], y[N]; 
int seg[4*N], lazy[4 * N];
void push_down(int node, int l, int r)
{
 if (lazy[node] != -1)
 {
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  int lsz = m - l + 1;
  int rsz = r - m;
  seg[n1] = lazy[node] * lsz;
  seg[n2] = lazy[node] * rsz;
  lazy[n1] = lazy[n2] = lazy[node];
  lazy[node] = -1; 
 }
}
void build(int node = 0, int l = 0, int r = n-1)
{
 if (l == r)
 {
  seg[node] = (y[l] == '1'? 1: 0); 
  lazy[node] = -1; 
  return;
 }
 int m = (l+r)>>1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 build(n1, l, m);
 build(n2, m+1, r);
 seg[node] = seg[n1] + seg[n2];
 lazy[node] = -1; 
}
void update(int le, int re, int val, int node = 0, int l = 0, int r = n-1)
{
 if (l > re || r < le)return;
 if (l >= le && r <= re)
 {
  seg[node] = val * (r-l+1);
  lazy[node] = val;
  return;
 }
 push_down(node, l, r);
 int m = (l+r)>>1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1;
 update(le, re, val, n1, l, m);
 update(le, re, val, n2, m+1, r);
 seg[node] = seg[n1] + seg[n2];
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
 if (l > re || r < le)return 0;
 if (l >= le && r <= re)
  return seg[node];
 push_down(node, l, r);
 int m = (l+r)>>1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1;
 return query(le, re, n1, l, m) + query(le, re, n2, m+1, r); 
}
void test()
{
 scanf("%d%d", &n, &q);
 scanf(" %s", x);
 scanf(" %s", y);
 for (int i = 0; i < q; i++)
  scanf("%d%d", Q[i], Q[i]+1); 
 build();
 bool ok = 1;
 for (int i = q-1; i >= 0; i--)
 {
  int l = Q[i][0] - 1; 
  int r = Q[i][1] - 1;
  int sum = query(l, r);
  int len = r-l+1;
  if (sum * 2 == len)
  {
   ok = 0;break;
  }
  int val = (sum * 2 < len? 0: 1); 
  update(l, r, val);
 }
 for (int i = 0; i < n; i++)
 {
  if ((x[i]-'0') != query(i, i))
  {
   ok = 0;
   break;
  }
 }
 if (ok)
  printf("YES\n");
 else 
  printf("NO\n"); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test();
}
