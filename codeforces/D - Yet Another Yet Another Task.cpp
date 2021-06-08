// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 9;
int a[N], n, ans;
void solve(int val)
{
  int cur = 0;
  for (int i = 0; i < n; i++)
  {
    cur += a[i];
    if (a[i] > val || cur < 0)
      cur = 0;
    ans = max(ans, cur-val);
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 1; i <= 30; i++)
    solve(i);
  printf("%d\n", ans);
}
