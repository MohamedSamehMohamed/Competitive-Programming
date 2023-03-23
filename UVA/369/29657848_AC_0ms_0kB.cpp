// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, k; 
int main()
{
 while(scanf("%d%d", &n, &k) && (n||k))
 {
  long long ret = 1;
  int K = k; 
  k = max(k, n-k);  
  for (int i = 1 + k; i <= n; i++)
  {
   // ret = ret * i / (i-k); 
   long long q = ret / (i-k);
   long long rem = ret - q * (i-k);
   ret = q * i + rem * i / (i-k);
  }
  printf("%d things taken %d at a time is %lld exactly.\n", n, K, ret); 
 }
}
