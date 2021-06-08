// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int a[N], a1[N], frq[N], suf[N], seg[N<<1], n, sz;
void update(int pos, int val, int node = 0, int l = 0, int r = n)
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
int query(int le, int re, int node = 0, int l = 0, int r = n)
{
 if (l > re || r < le)return 0;
 if (l >= le && r <= re)return seg[node];
 int m = (l+r) >> 1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 return query(le, re, n1, l, m) + query(le, re, n2, m+1, r); 
}
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
 {
  scanf("%d", a+i);
  a1[sz++] = a[i]; 
 }
 sort(a1, a1+sz);
 sz = unique(a1, a1+sz) - a1;
 for (int i = 0; i < n; i++)
  a[i] = lower_bound(a1, a1+sz, a[i]) - a1; 
 for (int i = 0; i < n-1; i++)
  frq[a[i]]++; 
 suf[a[n-1]]++; 
 update(suf[a[n-1]], 1);
 long long ans = 0;
 for (int i = n-2; i >= 0; i--)
 {
  ans += query(1, frq[a[i]]-1); 
  frq[a[i]]--;
  suf[a[i]]++;
  update(suf[a[i]], 1); 
 }
 printf("%lld\n", ans); 
}
