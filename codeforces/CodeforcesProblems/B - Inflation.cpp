// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 104;
int a[N], n, k;
void test()
{
 scanf("%d%d", &n, &k);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i);
 long long pre = a[0], tot = 0; 
 for (int i = 1; i < n; i++)
 {
  if ((1LL*100*a[i]) <= 1LL*k * pre)
  {
   pre += a[i];
   continue; 
  }
  long long l = 0, r = 1e13, ans = 0;
  
  while(l <= r)
  {
   long long m = (l+r)>>1LL;
   
   if ((1LL*100*a[i]) <= k * (m+pre))
   {
    ans = m;
    r = m-1;
   }else 
   {
    l = m+1; 
   }
  }
  tot += ans; 
  pre += ans + a[i]; 
 }
 printf("%lld\n", tot); 
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
   test();
   
}
