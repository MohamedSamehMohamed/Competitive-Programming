// Author : Mohamed Sameh
// created in: 10:07 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, mod = 1e9 + 7;
int n, k;
int a[N];
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
};
void test(){
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
  }
  Counting c(mod);
  sort(a, a+n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    // how many times max
    if (i >= k-1){
      sum = (sum + 1LL * a[i] * c.nCr(i, k-1)) % mod;
    }
    // hom many times min
    if (n-i-1 >= k-1){
      sum = (sum - 1LL * a[i] * c.nCr(n-i-1, k-1)) % mod;
    }
    if (sum < 0) sum += mod;
  }
  printf("%lld\n", sum);
}
int main()
{
  test();
}