// Author : Mohamed Sameh
// created in: 9:36 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
/*
 * c = ad + b
 * c = 0
 * ad + b = 0
 * ad = -b
 * d = -b/a
 */
void test(){
  scanf("%d", &n);
  map<vector<int>, int> mp;
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
  }
  int mx = 0, noEffort = 0;
  for (int i = 0; i < n; i++){
    int b;scanf("%d", &b);
    if (a[i] == 0) {
      if (b == 0) noEffort++;
      continue;
    }
    int g = __gcd(abs(a[i]), abs(b));
    int n1 = abs(a[i]) / g;
    int n2 = abs(b) / g;
    n1 *= (1LL * a[i] * b < 0? -1: 1);
    mx = max(mx, ++mp[{n1, n2}]);
  }
  printf("%d\n", mx + noEffort);
}
int main()
{
  test();
}