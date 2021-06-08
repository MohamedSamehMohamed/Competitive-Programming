// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, mi, a[N]; 
long long pre[N]; 
int seg[4*N]; 
int merge(int l, int r)
{
 return pre[seg[l]] >= pre[seg[r]]? seg[l]: seg[r]; 
}
void build(int node = 0, int l = 1, int r = n)
{
 if (l == r)
 {
  seg[node] = l;
  return; 
 }
 int m = (l+r) >> 1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1;
 build(n1, l, m);
 build(n2, m+1, r);
 seg[node] = merge(n1, n2); 
}
int query(long long val, int node = 0, int l = 1, int r = n)
{
 if (pre[seg[node]] < val)return -1;
 if (l == r)
  return seg[node]; 
 int m = (l+r) >> 1; 
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 if (pre[seg[n1]] >= val) 
  return query(val, n1, l, m); 
 else 
  return query(val, n2, m+1, r);
}
void test()
{
 scanf("%d%d", &n, &mi);
 pre[0] = 0;
 long long mx = 0; 
 for (int i = 1; i <= n; i++)
 {
  scanf("%d", a+i); 
  pre[i] = pre[i-1] + a[i];
  mx = max(mx, pre[i]);  
 }
 build(); 
 while(mi--)
 {
  int x;scanf("%d", &x);
  // check for prefix with sum >= x
  // if not exist check the cycle sum 
  int idx = query(1LL*x);
  if (idx != -1 && pre[idx] >= x)
  {
   printf("%d ", idx-1); 
   continue; 
  } 
  if (pre[n] <= 0)
  {
   printf("-1 "); 
   continue;
  }
  long long rep = max(1LL, (x-mx) / pre[n] - 1); 
  x -= rep * pre[n];
  long long ans = rep * n - 1;
  while(x > 0)
  { 
  idx = query(x); 
  if (idx == -1 || pre[idx] < x)
  {
   x-= pre[n]; 
   ans += n; 
  }else 
  {
   ans++; 
   ans += idx-1;
   break; 
  }
  }
  printf("%lld ", ans); 
 }
 printf("\n"); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
