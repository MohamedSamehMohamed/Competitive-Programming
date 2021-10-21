#include<bits/stdc++.h>
const int N = 2e5, mod = 1e9 + 7;
int fact[N], inv[N];
int mul(long long x, long long y)
{
    x %= mod;
    y %= mod;
    if (x < 0) x += mod;
    if (y < 0) y += mod;
    return x * y % mod;
}
int sub(long long x, long long y)
{
    x %= mod;
    y %= mod;
    x -= y;
    while (x < 0) x += mod;
    return x;
}
int add(long long x, long long y)
{
    x %= mod;
    y %= mod;
    if (x < 0) x += mod;
    if (y < 0) y += mod;
    x += y;
    if (x >= mod)x -= mod;
    return x;
}
int fast(int b, int p)
{
    if (p == 0)return 1;
    if (p&1)return mul(b, fast(b, p-1));
    int cur = fast(b, p/2);
    return mul(cur, cur);
}
int nPr(int n, int r)
{
    return mul(fact[n], inv[n-r]);
}
int nCr(int n, int r)
{
    return mul(mul(fact[n], inv[r]), inv[n-r]);
}
void Prepare()
{
    fact[0] = 1;
    inv[0] = fast(1, mod-2);
    for (int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i-1], i);
        inv[i]  = fast(fact[i], mod-2);
    }
}
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
};