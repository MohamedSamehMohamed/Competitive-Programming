#include <bits/stdc++.h>
using namespace std;
int n;
/*
* a^2 = 2b+1
* b = c - 1
* c = b + 1
*
 * 2b = a^2 - 1
 * b = (a^2 - 1) / 2
*
*/
void test(){
  scanf("%d", &n);
  int l = 0, r = n, m, cnt = 0;
  while (l <= r){
    m = (l+r) >> 1;
    int odd = 2 * m + 1;
    long long c = (1LL * odd * odd - 1) / 2LL + 1;
    if (c <= n)
      cnt = m, l = m + 1;
    else
      r = m - 1;
  }
  printf("%d\n", cnt);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
/*
 * a^2 + b^2 = c^2
 *
 * (a^2 - b)^2 = c^2
 *
 * a^4 + b^2 - 2 * a^2 * b = c^2
 *
 * a^4 + b^2 - 2 * a^2 * b = a^2 + b^2
 * a^4 - 2 * a^2 * b = a^2
 *
 * a^2 - 2b = 1
 *
 * a^2 = 2b + 1
 *
 * c = a^2 - b
 * c = 2b+1 - b
 * c = b+1
 *
 * a^2 = 2b + 1
 * c = b + 1
 *
 * a^2 = 2b+1
 * b = c - 1
 * c = b + 1
 *
 *
 */