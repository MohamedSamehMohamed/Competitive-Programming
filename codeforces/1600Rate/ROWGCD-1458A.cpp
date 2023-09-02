// Author : Mohamed Sameh
// created in: 2:45 PM
#include <bits/stdc++.h>
using namespace std;
int n, m;
void test(){
  scanf("%d%d", &n, &m);
  long long g = 0;
  long long a1 = 0;
  scanf("%lld", &a1);
  for (int i = 1; i < n; i++){
    long long x;
    scanf("%lld", &x);
    g = __gcd(g, x - a1);
  }
  for (int i = 0; i < m; i++){
    long long x;
    scanf("%lld", &x);
    printf("%lld ", abs(__gcd(g, a1 + x)));
  }
}
int main()
{
  test();
}