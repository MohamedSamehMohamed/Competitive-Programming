// Author : Mohamed Sameh
// created in: 4:51 PM
#include <bits/stdc++.h>
using namespace std;
class Counting
{
public:
  int mod;
  bool has_mod = false;
  Counting(int _mod): mod(_mod), has_mod(true){}
  Counting(){}
  vector<int> fact, inv;
  long long take_mod(long long x)
  {
    x %= mod;
    if (x < 0) x += mod;
    return x;
  }
  long long mul(long long x, long long y)
  {
    if (!has_mod)
      return x * y;
    x = take_mod(x);
    y = take_mod(y);
    return take_mod(x * y);
  }
  long long sub(long long x, long long y)
  {
    if (!has_mod)
      return x - y;
    x = take_mod(x);
    y = take_mod(y);
    return take_mod(x - y);
  }

  long long add(long long x, long long y)
  {
    if (!has_mod)
      return x + y;
    x = take_mod(x);
    y = take_mod(y);
    return take_mod(x + y);
  }
  long long fast(long long b, long long p)
  {
    if (p == 0)return 1;
    if (p&1)return mul(b, fast(b, p-1));
    long long cur = fast(b, p/2);
    return mul(cur, cur);
  }
  void Prepare(int n)
  {
    if (fact.empty())fact.push_back(1);
    if (inv.empty())inv.push_back(fast(1, mod - 2));
    int sz = fact.size();
    while(sz <= n)
    {
      fact.push_back(mul(sz, fact.back()));
      inv.push_back(fast(fact.back(), mod - 2));
      sz++;
    }
  }
  long long Fact(int n)
  {
    Prepare(n);
    return fact[n];
  }
  long long nPr(int n, int r)
  {
    if (n < r)return 0;
    Prepare(n);
    return mul(fact[n], inv[n-r]);
  }
  long long nCr(int n, int r)
  {
    if (n < r)
      return 0;
    Prepare(n);
    return mul(mul(fact[n], inv[n-r]), inv[r]);
  }
  long long div(int a, int b){
    return mul(a, fast(b, mod - 2));
  }
}C;
const int N = 2e5 + 9, mod = 998244353;
char s[N];
int a[N];
void test(){
  scanf(" %s", s);
  int n = strlen(s);
  int index = 0;
  for (int i = 0; i < n; i++){
    int j = i + 1;
    while (j < n && s[j] == s[j-1])
      j++;
    if (j-i > 1)
      a[index++] = j - i;
    i = j - 1;
  }
  n = index;
  int need = 0;
  long long ways = 1;
  long long fac = 1;
  for (int i = 0; i < n; i++){
    need += a[i] - 1;
    ways = (1LL * ways * C.nCr(a[i], a[i]-1)) % mod;
  }
  for (int i = 1; i <= need; i++)
    fac = (fac * i) % mod;
  ways = (ways * fac) % mod;
  printf("%d %lld\n", need, ways);
}
int main()
{
  C = Counting(mod);
  C.Prepare(N);
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}