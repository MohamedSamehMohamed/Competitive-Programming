// Author : Mohamed Sameh
// created in: 2:48 PM
#include <bits/stdc++.h>
using namespace std;
long long n, x, k;
long long countTo(long long d, long long cur){
  if (d < 0 || cur < 1) return 0;
  if (d == 0) return 1;
  long long l = cur, r = cur;
  while (d--){
    l = l * 2;
    r = r * 2 + 1;
    if (l > n) return 0;
  }
  return min(n, r) - l + 1;
}
void test(){
  scanf("%lld%lld%lld", &n, &x, &k);
  long long ans = 0, child = -1;
  while (x >= 1){
    ans += countTo(k, x);
    //cout << "from node: " << x << ": distance " << k <<" " << countTo(k, x) <<"\n";
    // remove my child if I count it
    ans -= countTo(k - 1,child);
    child = x;
    x >>= 1LL;
    k--;
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
    test();
}