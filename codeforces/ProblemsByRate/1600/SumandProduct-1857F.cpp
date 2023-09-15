// Author : Mohamed Sameh
// created in: 7:57 AM
#include <bits/stdc++.h>
using namespace std;
int n, q;
long long x, y;
long long getSqrt(long long D) {
  long long l = 1, r = 2e9, m, sq = 0;
  while (l <= r){
    m = (l+r) >> 1LL;
    if (m <= D / m)
      sq = m, l = m + 1;
    else
      r = m - 1;
  }
  return sq;
}

void test(){
  scanf("%d", &n);
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    int val;scanf("%d", &val);
    mp[val]++;
  }
  /*
   * x^2 + bx + c = 0
   * D = b^2 - 4c
   * x1 = (b - sqrt(D)) / 2
   * x2 = (b + sqrt(D)) / 2
   */
  auto add = [&](long long A, long long B){
    if (A + B != x || A * B != y || max(abs(A), abs(B)) > (int)2e9)
      return 0LL;
    if (A == B){
      int len = mp[A];
      return (1LL * len * (len-1)) / 2;
    }
    return 1LL * mp[A] * mp[B];
  };
  scanf("%d", &q);
  while (q--){
    scanf("%lld%lld", &x, &y);
    // a[j]^2 - x a[j] + y = 0
    long long D = 1LL * x * x - 4LL * y;
    long long sqrtD = getSqrt(D);
    long long x1 = (x - sqrtD) / 2;
    long long x2 = (x + sqrtD) / 2;
    long long ans = add(x1, x2);
    printf("%lld ", ans);
  }
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}