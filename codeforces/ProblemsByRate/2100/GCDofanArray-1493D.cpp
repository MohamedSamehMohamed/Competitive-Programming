// Author : Mohamed Sameh
// created in: 4:01 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, mod = 1e9 + 7;
int n, q;
int sieve[N];
vector<vector<int>> factorize[N];
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
  for (int i = 2; i < N; i++){
    int cur = i;
    while (cur != 1){
      int cnt = 0;
      int d = sieve[cur];
      while (cur % d == 0){
        cur /= d;
        cnt++;
      }
      factorize[i].push_back({d, cnt});
    }
    sort(factorize[i].begin(), factorize[i].end());
  }
}
map<int, set<vector<int>>> arrayFactors;
map<int, int> adj[N];

int fast(int b, int p)
{
  if (p < 0){
    return fast(fast(b, -p), mod - 2);
  }
  if (p == 0)return 1;
  if (p&1)return (1LL * b * fast(b, p - 1)%mod)%mod;
  int cur = fast(b, p/2) % mod;
  return 1LL * cur * cur % mod;
}
void test(){
  Sieve();
  // N = product of the first 7 primes
  scanf("%d%d", &n, &q);

  for (int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    for(auto factor: factorize[x]){
      arrayFactors[factor[0]].insert({factor[1], i});
      adj[i][factor[0]] += factor[1];
    }
  }
  auto get_effect = [&](int p){
    if (arrayFactors[p].size() == n){
      return arrayFactors[p].begin()->at(0);
    }
    return 0;
  };
  int gcd = 1;
  for (auto it: arrayFactors){
    int rep = get_effect(it.first);
    int d = it.first;
    gcd = (1LL * gcd * fast(d, rep)) % mod;
  }
  while (q--){
    int index, x;
    scanf("%d%d", &index, &x);
    index--;
    for (int i = 0; i < factorize[x].size(); i++){
      int d = factorize[x][i][0];
      int rep = factorize[x][i][1];
      int old_rep = adj[index][d];
      int effect = get_effect(d);
      arrayFactors[d].erase({old_rep, index});
      adj[index][d] += rep;
      arrayFactors[d].insert({rep + old_rep, index});
      effect = get_effect(d) - effect;
      gcd = (1LL * gcd * fast(d, effect)) % mod;
    }
    printf("%d\n", gcd);
  }
}
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int main()
{
  startTime = clock();
  test();
  cerr << getCurrentTime() << " ms\n";
}