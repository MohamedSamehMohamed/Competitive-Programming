// Author : Mohamed Sameh
// created in: 5:23 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int sieve[N];
vector<int> primes;
void Sieve() {
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
//  for (int i = 2; i < N; i++){
//    if (adj[i].size() == 0) continue;
//    sort(adj[i].begin(), adj[i].end());
//    ranges.push_back({2 * adj[i][0], 2 * adj[i].back(), i});
//  }
//  sort(ranges.begin(), ranges.end(), [](vector<int>&A, vector<int>&B){
//    if (A[0] != B[0]) return A[0] < B[0];
//    return A[1] > B[1];
//  });
}
void test(){
  int l, r;
  scanf("%d%d", &l, &r);
  for (int i = 0; i < 1000; i++){
    int val = primes[i];
    for (int j = max(2, l-val); j <= min(r - val, l + val); j++){
      if (j % val == 0){
        printf("%d %d\n", val, j);
        return;
      }
    }
  }
  printf("-1\n");
}
int main()
{
  Sieve();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}