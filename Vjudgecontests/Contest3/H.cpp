// Author : Mohamed Sameh
// created in: 10:42 PM
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
}c;
const int N = 1e5 + 9, mod = 1e9 + 7;
int n, k;
void test(){
  c = Counting(mod);
  scanf("%d%d", &n, &k);
  c.Prepare(n);
  long long sum = 0;
  vector<int> ways(k+1, 0);
  for (int i = k; i >= 1; i--){
    int cnt = k / i;
    ways[i] = c.fast(cnt, n);
    for (int j = 2 * i; j <= k; j+=i)
      ways[i] = (ways[i] - ways[j] + mod) % mod;
    sum = (sum + c.mul(i, ways[i])) % mod;
  }
  printf("%lld\n", sum);
}
int main()
{
  test();
}