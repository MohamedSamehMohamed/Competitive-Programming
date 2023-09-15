#include<bits/stdc++.h>
using namespace std;
long long p, q, n, z, e, d;
bool isPrime(long long number)
{
 for (long long i = 2; i <= number/i; i++)
  if (number % i == 0)return 0;
 return number > 1;
}
long long getPrime(long long start)
{
 for (long long i = start; ; i++)
  if (isPrime(i))
   return i;
 return -1;
}
long long extendEcliden(long long a, long long b, long long &x, long long &y)
{
 if (b == 0)
 {
  x = 1;
  y = 0;
  return a;
 }
 long long x1, y1;
 long long d = extendEcliden(b, a % b, x1, y1);
 x = y1;
 y = x1 - y1 * (a/b);
 return d;
}
long long modInverse(long long x, long long mod)
{
 long long X, Y;
 long long g = extendEcliden(x, mod, X, Y);
 return (X%mod + mod) % mod;
}
long long getEvalue()
{
 for (long long i = 2; i < z; i++)
  if (__gcd(i, z) == 1)
   return i;
 return -1;
}
void GenerateKey()
{
 long long start = 3;
 p = getPrime(start);
 q = getPrime(p*p);
 n = p * q;
 z = (p-1) * (q-1);
 e = getEvalue();
 d = modInverse(e, z);
 if (e == d) d += z;
 //printf("P: %lld\nQ: %lld\nn: %lld\nZ: %lld\nE: %lld\nD: %lld\n", p, q, n, z, e, d);
}
long long fastPower(long long a, long long b, long long mod)
{
 long long ret = 1;
 while(b)
 {
  if (b & 1)ret = (ret * a) % mod;
  b >>= 1LL;
  a = (a * a) % mod;
 }
 return ret;
}
long long Encrypt(long long P)
{
 return fastPower(P, e, n);
}
long long Decrypt(long long C)
{
 return fastPower(C, d, n);
}
void test()
{
 long long PlainTextValue;
 cin >> PlainTextValue;
 long long C = Encrypt(PlainTextValue);
 long long P = Decrypt(C);
}
int main()
{
 GenerateKey();
 test();
}
