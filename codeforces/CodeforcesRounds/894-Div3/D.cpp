// Author : Mohamed Sameh
// created in: 5:00 PM
#include <bits/stdc++.h>
using namespace std;
long long n;
void test(){
  scanf("%lld", &n);
  // n = a * (a-1) / 2
  // 2n = a * (a-1)
  // 2n/ a = (a-1)
  // 2n/a > (a-1)
  long long l = 1, r = 1e12, m, ans = -1;
  while (l <= r){
    m = (l+r) >> 1LL;
    if (2LL * n / m >= m - 1)
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  ans += n - ((ans * (ans - 1)) >> 1LL);
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}