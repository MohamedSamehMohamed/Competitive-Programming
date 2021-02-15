// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, m, p; 
void test()
{
 long long tot = (1LL * (n-7) * (m-7) + p) / 2; 
 printf("%lld\n", tot); 
}
int main()
{
 while(scanf("%d%d%d", &n, &m, &p) && (n+m+p!=0))
  test(); 
}
