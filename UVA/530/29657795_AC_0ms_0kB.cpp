// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
/*
nCk == n!/ (n-k)! * !k 
5C3 -> 5!/ 2! 3! [5 * 4]= 

coach Trick:
given a, b, c: calculate ab/c c divides ab, but not nessery a, b 

The Trick avoids the overflow given that the result ab/c is not outof limit...
The target is to divide a/c before multiplication
 
let rem = a % c 
let q = a / c [floor]
so, a = q * c + rem

ab/c == (q*c+rem)*b/ c 
(q*c*b)/c + (rem * b) / c 
q*b + rem*b/c 
*/
int n, k; 
int main()
{
 while(scanf("%d%d", &n, &k) && (n||k))
 {
  int ret = 1;
  k = max(k, n-k);  
  for (int i = 1 + k; i <= n; i++)
  {
   // ret = ret * i / (i-k); 
   int q = ret / (i-k);
   int rem = ret - q * (i-k);
   ret = q * i + rem * i / (i-k);
  }
  printf("%d\n", ret); 
 }
}
