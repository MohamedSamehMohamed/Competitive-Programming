// Author : Mohamed Sameh
// created in: 9:34 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
long long k;
void test(){
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  if (sum <= k){
    printf("0\n");
    return;
  }
  sum -= a[0];
  long long ans = 1e18;
  for (int i = 0; i < n; i++){
    // x b c d x x <= k
    // (i+1)*x + sum <= k
    // (i+1) * x <= k - sum
    long long x = (k - sum) / (i+1);
    if (1LL*(i+1)*x+sum > k)x--;
    ans = min(ans, max(0LL, 1LL*a[0] - x) + i);
    sum -= a[n-i-1];
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}