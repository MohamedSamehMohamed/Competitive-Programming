// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 20;
int a1[N], a[N], b[N], n, sz;
long long seg[N<<1]; 
void upd(int pos, int val, int node = 0, int l = 0, int r = n)
{
	if (l > pos || r < pos)return; 
	if (l == r)
	{
		seg[node] += val; 
		return; 
	}
	int m = (l+r)>>1;
	int n1 = node * 2 + 1;
	int n2 = n1 + 1;
	upd(pos, val, n1, l, m);
	upd(pos, val, n2, m+1, r); 
	seg[node] = seg[n1] + seg[n2]; 
}
long long qur(int le, int re, int node = 0, int l = 0, int r = n)
{
	if (l > re || r < le)return 0;
	if (l >= le && r <= re)return seg[node];
	int m = (l+r) >> 1;
	int n1 = node * 2 + 1;
	int n2 = n1 + 1; 
	return qur(le, re, n1, l, m) + qur(le, re, n2, m+1, r); 
}
void compress()
{
  for (int i = 0; i < n; i++)
	a1[sz++] = a[i]; 
  sort(a1, a1+sz);
  sz = unique(a1, a1+sz) - a1;
  for (int i = 0; i < n; i++)
	a[i] = lower_bound(a1, a1+sz, a[i]) - a1;
}
void calB()
{
  // for each i store how many number less than a[i] 
  for (int i = n-1; ~i; i--)
  {
	 b[i] = qur(0, a[i]-1); 
	 upd(a[i], 1);
  }
  for (int i = 0; i < n; i++)
	upd(a[i], -1);
}
void build()
{
	for (int i = 0; i < n; i++)
		upd(a[i], b[i]); 
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i); 
  compress(); 
  calB(); 
  build();
  long long ans = 0;
  for (int i = 0; i < n-2; i++)
  {
	ans += qur(0, a[i]-1); 
	upd(a[i], -b[i]); 
  }
  printf("%lld\n", ans);
}
