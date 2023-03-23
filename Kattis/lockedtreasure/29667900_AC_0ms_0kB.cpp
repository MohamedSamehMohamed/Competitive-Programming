// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long NCK(int n, int k)
{
 long long ret = 1; 
 for (int i = 1 + k; i <= n; i++)
 {
  long long q = ret / (i-k);
  long long rem = ret - q * (i-k);
  ret = q * i + rem * i / (i-k);
 }
 return ret; 
}
void test()
{
 int n, k;
 scanf("%d%d", &n, &k);
 long long ret = NCK(n, k-1);
 printf("%lld\n", ret); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
