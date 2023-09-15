// Author : Mohamed Sameh
// created in: 9:30 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int a[N], n, k;
bool can(int x){
  if (a[n-1] >= x) return 1;
  for (int i = n-2; i >= 0; i--){
      if (a[i] >= x) return 1;
      int need = x - a[i];
      for (int j = i + 1; j < n; j++){
        if (need > k) break;
        if (a[j] >= x - j + i)
          return true;
        need += (x-j+i) - a[j];
      }
  }
  return 0;
}
void test(){
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), ans = max(ans, a[i]);
  int l = 1, r = 2e8, m;
  while (l <= r)
  {
    m = (l+r) >> 1;
    if (can(m))
      ans = m, l = m + 1;
    else
      r = m - 1;
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