// Author : Mohamed Sameh
// created in: 6:01 PM
#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long sum(int xx){
  return (1LL * (xx+1) * xx) / 2;
}
void test(){
  scanf("%d%d%d", &n, &x, &y);
  int dx = n / x;
  int dy = n / y;
  int common = 1LL * n / ((1LL * x * y)/__gcd(x, y));
  dx -= common;
  dy -= common;
  //printf("%d %d\n", dx, dy);
  //cerr << sum(n) << " " << sum(n-dx) <<" " <<sum(n) - sum(n-dx) <<"\n";
  long long ans = sum(n)-sum(n-dx) -sum(dy);
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}