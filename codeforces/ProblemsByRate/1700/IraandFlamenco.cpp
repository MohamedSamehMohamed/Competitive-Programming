#include<bits/stdc++.h>
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
};
const int N = 2e5 + 9, mod = 1e9 + 7;
int n, m;
int a[N];
Counting c(mod);
void solve(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  vector<vector<int>> ar;
  for (int i = 0; i < n; i++){
    int j = i + 1;
    while (j < n && a[j] == a[i])
      j++;
    ar.push_back({a[i], j - i});
    i = j - 1;
  }
  n = ar.size();
  int l = 0, r = 0;
  int frqProd = 1;
  int ans = 0;
  while (r < n){
    while (r < n && ar[r][0] - ar[l][0] < m){
      frqProd = c.mul(frqProd, ar[r][1]);
      r++;
    }
    if (r - l >= m){
      int ways = c.mul(c.nCr(r-l, m), frqProd);
      ans = c.add(ans, ways);
    }
    frqProd = c.div(frqProd, ar[l][1]);
    l++;
  }
  printf("%d\n", ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
} 
