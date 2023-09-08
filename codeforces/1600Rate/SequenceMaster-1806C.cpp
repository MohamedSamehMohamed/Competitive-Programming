// Author : Mohamed Sameh
// created in: 3:14 AM
#include <bits/stdc++.h>
using namespace std;
/*
 * a1, a2, a3, a4, a5, a6
 * a1 != a2
 * a1 * a3 * a4 = a2 + a5 + a6 ( 1 )
 * a2 * a3 * a4 = a1 + a5 + a6 ( 2 )
 * ( 1 ) - ( 2 )
 * (a1 * a3 * a4) - (a2 * a3 * a4) = (a2 + a5 + a6) - (a1 + a5 + a6)
 * (a1 * a3 * a4) - (a2 * a3 * a4) = a2 - a1
 * (a1 - a2) * (a3 * a4) = a2 - a1
 * (a1 - a2) * (a3 * a4) - (a2 - a1) = 0
 * (a1 - a2) * (a3 * a4) + a1 - a2 = 0
 * (a1 - a2) * ((a3 * a4) + 1) = 0
 * a1 != a2 so a1-a2 != 0
 * to be true (a1 - a2) * ((a3 * a4) + 1) = 0, ((a3*a4) + 1) = 0
 * a3 * a4 = -1 [(n-1) number]
 *
 * a3, a4, a5, a6
 * a3 * a4 = -1
 * a3 * a5 = -1
 * a4 * a5 = -1
 * a4 * a6 = -1
 * a5 * a6 = -1
 * a6 = -1/a4, -1 / a5
 * => a4 = a5
 * a4 = -1 / a5, -1 / a6
 * => a5 = a6
 * a5 = -1 / a3, -1 / a4
 * => a3 = a4
 * ->> a3 = a4 = a5 = a6
 * a3 * a4 = -1, a3^(n-1) = -1 , n must be even and a_i = -1
 *
 * a1 * a3 * a4 = a2 + a5 + a6 ( 1 )
 * a1 * -1 = a2 + (-(n-1))
 * -a1 = a2 + -n+1
 *
 * a1 + a2 = n - 1
 *
 * for
 * a1 = n, a2 = -1
 *
 */
const int N = 4e5 + 9;
int n, a[N];
void test(){
  scanf("%d", &n);
  long long ans = 0, sum = 0;
  for (int i = 0; i < 2 * n; i++){
    scanf("%d", a+i);
    ans += abs(a[i]);
    sum += abs(a[i] + 1);
  }
  if (n == 1){
    // 0 0, a1 a1, a2 a2
    ans = min(ans, 1LL * abs(a[0] - a[1]));
  }
  if (n % 2 == 0)
  {
    // 1  2  2  1    2 + 3 + 3 + 2 = 10
    // 2 -1 -1 -1 ->
    // 2 2 2 2
    if (n == 2)
      ans = min(ans,
                1LL*abs(a[0] - 2) + abs(a[1] - 2) +
                abs(a[2] - 2) + abs(a[3] - 2));

    for (int i = 0; i < 2 * n; i++){
      ans = min(ans, sum - abs(a[i] + 1) + abs(a[i] - n));
    }
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