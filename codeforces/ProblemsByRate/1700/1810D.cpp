// Author : Mohamed Sameh
// created in: 8:46 AM
#include <bits/stdc++.h>
using namespace std;
vector<long long> get_range(int a, int b, int n){
  long long walk = 1LL * (a-b) * (n-1);
  return {walk + b * (n!=1) + 1, walk + a};
}
long long get_days(int a, int b, long long n){
  long long days = (n+a-b-1) / (a-b);
  while (days > 1 && (days-2) * (a-b) + a >= n)
  {
    days--;
  }
  return days;
}
void test(){
  int q;
  scanf("%d", &q);
  long long l = -1, r = -1;
  while (q--){
    int type, a, b, n;
    scanf("%d%d%d", &type, &a, &b);
    if (type == 1){
      scanf("%d", &n);
      auto cur = get_range(a, b, n);
      int take = 1;
      if (l == -1){
        l = cur[0];
        r = cur[1];
      }else {
        if (l > cur[1] || r < cur[0]) take = 0;
        else {
          l = max(l, cur[0]);
          r = min(r, cur[1]);
        }
      }
      printf("%d ", take);
    }else {
      if (l != -1)
      {
        long long d = get_days(a, b, l);
        if (l == r || d == get_days(a, b, r))
          printf("%lld ", d);
        else
          printf("-1 ");
      }
      else
        printf("-1 ");
    }
  }
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}