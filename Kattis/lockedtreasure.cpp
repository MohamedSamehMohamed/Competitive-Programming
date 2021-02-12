// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, k; 
void test()
{
 scanf("%d%d", &n, &k);
 k = max(k, n-k);
 long long ret = 1;   
 for (int i = 1 + k; i <= n; i++)
 {
  long long q = ret / (i-k);
  long long rem = ret - q * (i-k);
  ret = q * i + rem * i / (i-k);
 }
 printf("%lld\n", ret); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
