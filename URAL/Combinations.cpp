// Author : Mohamed Sameh
// created in: 7:31 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 9;
int n, m;
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
/*
   * n!/m! * (n-m)!
   * 5 3
   * n * (n-1) * (n-2) * (n-(n-m-1)) m+1
   * n * (n-1) * (n-3) * ..., (m+1)
   * 5 * 4
   *
   */
void test(){
  Sieve();
  scanf("%d%d", &n, &m);
  map<int, int> mp;
  int len = n - m;
  int down = len;
  auto factorize = [&](int num, int add){
    while (num != 1){
      mp[sieve[num]] += add;
      num /= sieve[num];
    }
  };
  for (int i = 0; i < len; i++){
    factorize(n--, 1);
  }
  while (down > 1){
    factorize(down--, -1);
  }
  int ans = 0;
  for (auto i: mp)
    ans += (i.second > 0);
  printf("%d\n", ans);
}
int main()
{
  test();
}