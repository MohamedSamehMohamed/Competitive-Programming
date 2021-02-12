// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, m, p; 
void test()
{
 n -= !p;
 m -= !p; 
 long long ans = 1LL*max(0,(n-7))*max(0, (m-7));
 printf("%lld\n", ans);  
}
int main()
{
 while(scanf("%d%d%d", &n, &m, &p) && (n+m+p!=0))
  test(); 
}
