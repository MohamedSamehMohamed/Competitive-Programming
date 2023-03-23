#include <bits/stdc++.h>
using namespace std;
void read_file(){
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 5e5 + 9; 
int sieve[N];
vector<int> factors[N];
void prepare_sieve()
{
  for(int i = 2; i < N; i++)
  {
    for(int j = i; j < N; j+=i)
    {
      if (sieve[j] == 0)sieve[j] = i; 
      sieve[j] = min(sieve[j], i); 
    }
  }
  for(int i = 2; i < N; i++)
  {
    int cur = i; 
    while(cur != 1)
    {
      int d = sieve[cur];
      factors[i].push_back(d);
      while (cur % d == 0)
      {
        cur /= d; 
      }
    }
  }
}
int n, q, a[200009], in[200009]; 
long long ans = 0; 
int sz, ones; 
int frq[N];
long long sum(int val)
{
  return val;
  // return (1LL * val * (val+1) ) / 2;
} 
void rem(int val)
{
  sz--; 
  int cur_size = factors[val].size();
  long long tot = 0; 
  for (int msk = 1; msk < (1<<cur_size); msk++)
  {
    int odd = 0; 
    long long prod = 1; 
    for(int i = 0; i < cur_size; i++)
    {
      if (msk & (1<<i))
      {
        odd ^= 1; 
        prod *= factors[val][i];
      }
    }
    frq[prod]--; 
  }
  for(int msk = 1; msk < (1<< cur_size); msk++)
  {
    int odd = 0; 
    long long prod = 1; 
    for(int i = 0; i < cur_size; i++)
    {
      if (msk & (1<<i))
      {
        odd ^= 1; 
        prod *= factors[val][i];
      }
    }
    if (odd)
      tot += frq[prod];
    else 
      tot -= frq[prod];  
  }
  ans -= tot; 
}
void add(int val)
{
  sz++; 
  int cur_size = factors[val].size();
  long long tot = 0; 
  for(int msk = 1; msk < (1<< cur_size); msk++)
  {
    int odd = 0; 
    long long prod = 1; 
    for(int i = 0; i < cur_size; i++)
    {
      if (msk & (1<<i))
      {
        odd ^= 1; 
        prod *= factors[val][i];
      }
    }
    if (odd)
      tot += frq[prod];
    else 
      tot -= frq[prod];  
  }
  ans += tot; 
  for (int msk = 1; msk < (1<<cur_size); msk++)
  {
    int odd = 0; 
    long long prod = 1; 
    for(int i = 0; i < cur_size; i++)
    {
      if (msk & (1<<i))
      {
        odd ^= 1; 
        prod *= factors[val][i];
      }
    }
    frq[prod]++; 
  }
}
int main()
{
  read_file(); 
  prepare_sieve();
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  sz = 0;
  while(q--)
  {
    int idx;scanf("%d", &idx); idx--;
    if (in[idx])
    {
      // rem 
      rem(a[idx]);
      in[idx] ^= 1;
    }else 
    {
      // add 
      add(a[idx]); 
      in[idx] ^= 1; 
    }
    long long tot = (1LL * sz * (sz-1)) / 2;
    printf("%lld\n", tot - ans);
  }
}