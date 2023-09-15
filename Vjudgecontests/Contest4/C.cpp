// Author : Mohamed Sameh
// created in: 10:07 PM
#include <bits/stdc++.h>
using namespace std;
long long p, q;
void test(){
  scanf("%lld%lld", &p, &q);
  if (p < q || p % q != 0){
    printf("%lld\n", p);
    return;
  }
  // p % q == 0
  // q = 2^(a) * 3^(b) * 5 ^(c) ...
  // p = 2^(x) * 3^(y) * 5 ^(z) ...
  // x>=a, y>=b, z>=c
  /*
   * p % q == 0 means for each prime factor in q,
   * it exists in p with a higher or same exp
   * to make p % q != 0, decreases exp of one of primes factor of p
   */

  long long x = 1;
  int Q = q;
  for (int i = 2; i <= q / i; i++){
    if (q % i != 0) continue;
    while (q % i == 0)
      q /= i;
    long long cur = p;
    while (cur % Q == 0){
      cur /= i;
    }
    x = max(x, cur);
  }
  if (q != 1){
    long long cur = p;
    while (cur % Q == 0){
      cur /= q;
    }
    x = max(x, cur);
  }
  printf("%lld\n", x);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}