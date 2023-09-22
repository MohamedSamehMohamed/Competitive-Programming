// Author : Mohamed Sameh
// created in: 12:57 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], b[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d%d", a+i, b+i);
  }
  /*
   * C1 C2, C1 = C2 = C
   * d1*b1 = d2*b2
   * b1|C, b2|C -> C at least lcm(b1, b2)
   *
   * d1|a1 -> (* b1)
   * d1*b1|a1*b1 -> C|a1*b1,, C|a2|b2 -> C|gcd(a1b1, a2b2)
   */
  int ans = 1;
  long long gcd = 0, lcm = 1;
  for (int i = 0; i < n; i++){
    gcd = __gcd(gcd, 1LL * a[i] * b[i]);
    lcm = lcm / __gcd(lcm, 1LL * b[i]) * b[i];
    if (gcd % lcm){
      ans++;
      gcd = 1LL * a[i] * b[i];
      lcm = b[i];
    }
  }
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}