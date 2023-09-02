// Author : Mohamed Sameh
// created in: 2:26 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
    ans += a[i] >= a[i+1];
  int cur = ans;
  /*
   * \
   *  \
   *   \
   */
  for (int i = 0; i < n - 1; i++){
    cur -= a[i] >= a[i+1];
    if (i > 0)
      cur += a[i] >= a[i-1];
    ans = min(ans, cur + 1);
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