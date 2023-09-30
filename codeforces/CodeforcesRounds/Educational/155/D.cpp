// Author : Mohamed Sameh
// created in: 2:52 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9, mod = 998244353;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  long long ans = 0;
  for (int b = 0; b < 31; b++){
    int sum[2] = {0, 0};
    int cnt[2] = {0, 0};
    int pre = 0;
    cnt[0] = 1;
    sum[0] = -1;
    for (int i = 0; i < n; i++){
      pre ^= ((a[i] & (1LL<<b)) != 0);
      long long lens = (1LL * cnt[pre^1] * i - sum[pre^1]) % mod;
      ans = (ans + (1LL<<b) * lens) % mod;
      sum[pre] = (sum[pre] + i)%mod;
      cnt[pre]++;
    }
  }
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
}
int main()
{
  test();
}