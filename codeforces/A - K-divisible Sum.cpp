// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long n, k;
void test()
{
 
 scanf("%lld%lld", &n, &k);
 long long need = k*(max(0LL,(n-1))/k);
 k += need;  
 printf("%lld\n", (k+n-1)/n);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
   test();
   
}
