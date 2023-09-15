#include <bits/stdc++.h>
using namespace std;
long long n;
void test(){
  scanf("%lld", &n);
  long long a, b;
  a = b = 1;
  vector<long long> odds;
  for (int i = 2; i <= n / i; i++){
    long long cnt = 1;
    while (n % i == 0){
      n /= i;
      cnt *= i;
    }
    if (cnt != 1){
      odds.push_back(cnt);
    }
  }
  if (n != 1)
    odds.push_back(1LL*n);
  n = odds.size();
  long long mx = 1e12;
  for (int msk = 0; msk < (1<<n); msk++){
    long long curA = 1, curB = 1;
    for (int i = 0; i < n; i++){
      if (msk&(1<<i))
        curA *= odds[i];
      else
        curB *= odds[i];
    }
    if (max(curA, curB) < mx){
      a = curA;
      b = curB;
      mx = max(curA, curB);
    }
  }
  printf("%lld %lld\n", a, b);
}
int main()
{
  test();
}