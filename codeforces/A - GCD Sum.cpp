#include<bits/stdc++.h>
using namespace std;
long long n; 
long long sum(long long x)
{
 long long xx = 0;
 while(x)
 {
  xx += x % 10; 
  x /= 10;
 }
 return xx; 
}
void test()
{
 scanf("%lld", &n);
 while(__gcd(n, sum(n)) == 1)n++; 
 printf("%lld\n", n); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
 test();
}
