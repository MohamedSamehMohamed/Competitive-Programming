#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int a[N], a1[N], sz, seg[N<<1], n;  
void Compress()
{
 sz = 0;
 for (int i = 0; i < n; i++)
  a1[sz++] = a[i]; 
 sort(a1, a1 + sz); 
 // no need to unique as the input is unique, but let's finsh the compress process 
 sz = unique(a1, a1 + sz) - a1; 
 for (int i = 0; i < n; i++)
  a[i] = lower_bound(a1, a1 + sz, a[i]) - a1; 
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
 if (l > re || le > r) return 0; 
 if (l >= le && r <= re) return seg[node]; 
 int m = (l+r) >> 1;
 int n1 = node * 2 + 1; 
 int n2 = n1 + 1; 
 return query(le, re, n1, l, m) + query(le, re, n2, m+1, r); 
}
void update(int pos, int val, int node = 0, int l = 0, int r = n-1)
{
 if (l > pos || r < pos)return;
 if (l == r)
 {
  seg[node] += val;
  return;
 }
 int m = (l+r) >> 1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 update(pos, val, n1, l, m);
 update(pos, val, n2, m+1, r);
 seg[node] = seg[n1] + seg[n2];
}
void test()
{
 scanf("%d", &n);
 memset(seg, 0, sizeof seg); 
 for (int i = 0; i < n; i++)
  scanf("%d", a+i); 
 Compress(); 
 long long ans = 0;
 for (int i = n-1; i >= 0; i--)
 {
  ans += query(0, a[i]-1); 
  update(a[i], 1); 
 }
 printf("%lld\n", ans); 
}
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
  test(); 
}
