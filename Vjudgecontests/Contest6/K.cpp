// Author : Mohamed Sameh
// created in: 9:36 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m;
int sieve[N], marked[N];
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
void mark(int x){
  for (int i = x; i < N; i+=x)
    marked[i] = 1;
}
void test(){
  Sieve();
  scanf("%d%d", &n, &m);
  set<int> st;
  for (int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    while (x != 1){
      int d = sieve[x];
      while (x % d == 0)
        x /= d;
      st.insert(d);
    }
  }
  for (int i: st)
    mark(i);
  vector<int> ans;
  for (int i = 1; i <= m; i++)
    if (!marked[i])
      ans.push_back(i);
  printf("%d\n", (int)ans.size());
  for (int i: ans)
    printf("%d\n", i);
}
int main()
{
  test();
}