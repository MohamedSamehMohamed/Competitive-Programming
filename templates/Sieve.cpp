#include <vector>
using namespace std;

const int N = 1e6 + 9;
int sieve[N];
vector<int> primes;
void Sieve() {
  primes.clear();
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
// it uses sieve array
vector<vector<int>> factorize_fast(int x){
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
template<typename T>
vector<vector<T>> factorize(T x){
  vector<vector<T>> ret;
  for (T i = 2; i <= x / i; i++){
    T cnt = {};
    while (x % i == 0)
      x /= i, cnt++;
    if (cnt != 0)
      ret.push_back({i, cnt});
  }
  if (x != 1)
    ret.push_back({x, T(1)});
  return ret;
}