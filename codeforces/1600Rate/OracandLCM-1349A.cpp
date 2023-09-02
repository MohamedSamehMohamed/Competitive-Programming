// Author : Mohamed Sameh
// created in: 3:18 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int n;
int sieve[2*N];
vector<int> primes;
vector<int> frq[2*N];
void Sieve()
{
  sieve[0] = sieve[1] = 1;
  for(int i = 2; i < 2 * N; i++)
  {
    if (sieve[i] == 0)
    {
      sieve[i] = i;
      primes.push_back(i);
    }
    for(int &p: primes)
    {
      if (i * p >= 2 * N)
        break;
      sieve[i * p] = p;
    }
  }
}
int main()
{
  Sieve();
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    while (x != 1){
      int d = sieve[x];
      int cnt = 0;
      while (sieve[x] == d){
        cnt++;
        x /= d;
      }
      frq[d].push_back(cnt);
    }
  }
  long long gcd = 1;
  for (int i = 2; i < 2 * N; i++){
    if (frq[i].size() == 0 || frq[i].size() < n-1) continue;
    sort(frq[i].begin(), frq[i].end());
    int index = (frq[i].size() == n? 1: 0);
    for (int j = 0; j < frq[i][index]; j++)
      gcd *= i;
  }
  printf("%lld\n", gcd);
}