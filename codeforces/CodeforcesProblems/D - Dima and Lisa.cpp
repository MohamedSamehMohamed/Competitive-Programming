// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9; 
bool siev[N]; 
int p[N], n, sz; 
bool isPrime(int x)
{
 if (x < 0)return 0;
 if (x < N)return !siev[x]; 
 for (int i = 2; i <= x/i; i++)
  if (x % i == 0)
   return 0;
 return 1; 
}
void Siev()
{
 siev[0] = siev[1] = 1;
  for (int i = 2; i <= N/i; i++)
  {
   if (siev[i])continue; 
   for (int j = i * i; j < N; j+=i)
    siev[j] = 1; 
  }
 for (int i = 3; i < N; i++)
  if (!siev[i])
   p[sz++] = i; 
}
// n is odd 
// odd + odd -> even// can't be 2 
// odd = odd + odd + odd 
// odd = even + even  + odd  
int main()
{
 Siev();
 scanf("%d", &n);
 if (isPrime(n))
 {
  printf("1\n%d\n", n);  
  return 0;
 }
 if (isPrime(n-4))
 {
  printf("3\n2 2 %d\n", n-4); 
  return 0; 
 }
 for (int i = 0; i < sz; i++)
 {
  if (isPrime(n-2*p[i]))
  {
   printf("3\n%d %d %d\n", p[i], p[i], n-2*p[i]); 
   break; 
  }
 }
 
}
