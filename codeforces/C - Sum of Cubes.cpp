// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long n;
void test()
{
 scanf("%lld", &n);
 bool ok = 0; 
 for (int i = 1; !ok && i <= 10000; i++)
 {
  long long cur = 1LL * i * i * i; 
  if (cur > n)break; 
  long long tar = n - cur; 
  long long l = 1, r = 10000; 
  while(l <= r)
  {
   long long mid = (l+r)>>1LL; 
   long long curn = 1LL * mid * mid * mid; 
   if (curn == tar)
   {
    ok = 1;break;
   }
   if (curn < tar)
    l = mid + 1; 
   else 
    r = mid - 1; 
  }
 }
 printf("%s\n", (ok? "YES": "NO")); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
