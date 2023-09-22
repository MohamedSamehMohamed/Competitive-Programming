// Author : Mohamed Sameh
// created in: 8:57 PM
#include <bits/stdc++.h>
using namespace std;
int mod = 10;
long long mul(int a, int b){
  return (1LL * a * b) % mod;
}
long long fast(long long b, long long p)
{
  if (p == 0)return 1;
  if (p&1)return mul(b, fast(b, p-1));
  long long cur = fast(b, p/2);
  return mul(cur, cur);
}
void test(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int ans = fast(a, b);
  ans = fast(ans, c);
  printf("%d\n", ans);
}
int main()
{
  test();
}