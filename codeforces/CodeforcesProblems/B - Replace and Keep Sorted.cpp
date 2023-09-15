// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], n, q, k;
long long pre[N], prv[N], nex[N];
void test()
{
 scanf("%d%d%d", &n, &q, &k);
 for (int i = 0; i <= n; i++)pre[i] = 0; 
 for (int i = 0; i < n; i++) scanf("%d", a+i);
 for (int i = 0; i< n; i++)
 {
  prv[i] = a[i] - (i-1>=0? a[i-1]: 0) - 1; 
  nex[i] = (i+1 < n? a[i+1]: k+1) - a[i] - 1; 
  pre[i] = prv[i] + nex[i];
  if (i)pre[i] += pre[i-1]; 
  prv[i] = (i+1 < n? a[i+1]-2: 0);
  nex[i] = k-(i-1>=0? a[i-1]+1: 0);  
 }
 while(q--)
 {
  int l, r;
  scanf("%d%d", &l, &r);
  if (l == r)
  {
   printf("%d\n", k-1); 
   continue;
  }
  l--;r--;
  if (l + 1 == r)
  {
   printf("%lld\n", 1LL*a[r]-2 + k - (a[l] + 1));
   continue;
  }
  long long ans = prv[l] + nex[r];
  ans += (pre[r-1] - pre[l]);  
  printf("%lld\n", ans);
 }
}
int main()
{
 test(); 
}
