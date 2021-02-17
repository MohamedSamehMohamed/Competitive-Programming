// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
/*
 * calculate: Z_n + Z_n-1 - 2 * Z_n-2 
 * 
 * Z_n = S_n + P_n
 * S_n = 1^k + 2^k + 3^k + n^k
 * P_n = 1^1 + 2^2 + 3^3 + n^n 
 * 
 * Z_n + Z_n-1 = 2*(Z_n-1) - (Z_n - Z_n-1)
 * Z_n - Z_n-1 = S_n + P_n - S_n-1 - P_n-1 
 * 
 * S_n   = 1^k + 2^k + (n-1)^k + n^k 
 * S_n-1 = 1^k + 2^k + (n-1)^k 
 * S_n - S_n-1 = n^k 
 * 
 * P_n   = 1^1 + 2^2 + 3^3 + n^n
 * P_n-1 = 1^1 + 2^2 + (n-1)^(n-1)   
 * P_n - P_n-1 = n^n
 * 
 * >> Z_n - Z_n-1 = n^k + n^n
 * Z_n + Z_n-1 = 2*(Z_n-1) + (Z_n - Z_n-1) = 2*(Z_n-1) + n^k + n^n  
 * 
 * Z_n + Z_n-1 - 2*(Z_n-2) = 2*(Z_n-1) + n^k + n^n - 2*(Z_n-2)
 * 
 * 2*(Z_n-1) - 2*(Z_n-2) + n^k + n^n 
 * 
 * 2*(Z_n-1 - Z_n-2) + n^k + n^n 
 * 2*((n-1)^k + (n-1)^(n-1)) + n^k + n^n 
 * 
 *  
 * 
 *  
 */
int n, k, mod = 10000007;
int pow(int base, int p)
{
 int ret = 1; 
 while(p)
 {
  if (p&1) ret = (1LL * ret * base) % mod;
  base = (1LL * base * base) % mod; 
  p >>= 1; 
 }
 return ret; 
}
int Zn(int n, int k)
{
 return (pow(n, k) + pow(n, n))%mod;
}
int main()
{
 while(scanf("%d%d", &n, &k) && (n||k))
 {
  int ans = (2LL * Zn(n-1, k) + Zn(n, k)) % mod;
  printf("%d\n", ans); 
 }
}
