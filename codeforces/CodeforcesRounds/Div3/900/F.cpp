// Author : Mohamed Sameh
// created in: 6:27 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int sieve[N];
void Sieve() {
  vector<int> primes;
  sieve[0] = sieve[1] = 1;
  for (int i = 2; i < N; i++) {
    if (sieve[i] == 0) {
      sieve[i] = i;
      primes.push_back(i);
    }
    for (int &p: primes) {
      if (i * p >= N)
        break;
      sieve[i * p] = p;
    }
  }
}
int n, q;
map<int, int> mp;
vector<vector<int>> factorize(int x){
  vector<vector<int>> ret;
  while (x > 1){
    int d = sieve[x];
    int cnt = 0;
    while (x % d == 0){
      x /= d;
      cnt++;
    }
    ret.push_back({d, cnt});
  }
  return ret;
}
void test(){
  scanf("%d%d", &n, &q);
  int iniN = n;
  mp = map<int, int>();
  auto current = factorize(n);
  long long d_n = 1;
  for (auto it: current){
    mp[it[0]] += it[1];
    d_n *= (it[1] + 1);
  }
  while (q--){
    int k, x;
    scanf("%d", &k);
    if (k == 2){
      auto current = factorize(iniN);
      mp = map<int, int>();
      for (auto it: current){
        mp[it[0]] += it[1];
      }
      continue;
    }
    scanf("%d", &x);
    auto current = factorize(x);
    for (auto it: current){
      mp[it[0]] += it[1];
    }
    d_n = 1;
    for(auto it: mp)
    {
      d_n *= (it.second + 1);
    }
    bool can = 1;
    for (auto it : mp){
      int d = it.first;
      int cnt = 0;
      while (d_n % d == 0){
        d_n /= d;
        cnt++;
        if (cnt > it.second) break;
      }
      if (cnt > it.second) {
        can = 0;
        break;
      }
    }
    can &= (d_n == 1);
    if (can){
      printf("Yes\n");
    }else
      printf("No\n");

  }
  cout <<"\n";
}
int main()
{
  Sieve();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}