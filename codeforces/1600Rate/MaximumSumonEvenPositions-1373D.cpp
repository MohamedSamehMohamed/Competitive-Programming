// Author : Mohamed Sameh
// created in: 8:40 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  long long evenSum = 0, ans, cur1 = 0, cur2 = 0;
  for (int i = 0; i < n; i += 2)
  {
    evenSum += a[i];
  }
  ans = evenSum;
  for (int i = 1; i < n; i+=2){
    if (cur1 < 0) cur1 = 0;
    if (cur2 < 0) cur2 = 0;
    cur1 += a[i] - a[i-1];
    if (i + 1 < n)
      cur2 += a[i] - a[i+1];
    ans = max(ans, evenSum + max(cur1, cur2));
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