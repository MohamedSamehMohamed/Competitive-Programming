// Author : Mohamed Sameh
// created in: 4:53 PM
#include <bits/stdc++.h>
using namespace std;
int n, m;
void test(){
  scanf("%d%d", &n, &m);
  if (n % m == 0){
    printf("0\n");
    return;
  }
  int rem = n % m;
  long long ans = 0;
  // ay 7aga
  int cnt = 0;
  while (rem % m != 0){
    ans += rem;
    rem *= 2;
    rem = rem % m;
    cnt++;
    // hack me lol
    if (cnt > 400) break;
  }
  if (rem % m) ans = -1;
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}