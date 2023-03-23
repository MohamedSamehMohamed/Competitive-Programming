// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
/*
nCk == n!/ (n-k)! * !k 
5C3 -> 5!/ 2! 3! [5 * 4]= 
*/
int n, k; 
int main()
{
 while(scanf("%d%d", &n, &k) && (n||k))
 {
  long long ret = 1;
  k = max(k, n-k);  
  for (int i = 1 + k; i <= n; i++)
  {
   ret = ret * i / (i-k); 
  }
  printf("%lld\n", ret); 
 }
}
