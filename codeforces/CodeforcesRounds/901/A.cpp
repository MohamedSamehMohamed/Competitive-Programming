// Author : Mohamed Sameh
// created in: 4:28 PM
#include <bits/stdc++.h>
using namespace std;
int a, b, n;
int v[102];
void test(){
  scanf("%d%d%d", &a, &b, &n);
  for (int i = 0; i < n; i++)
    scanf("%d", v+i);
  long long ans = b;
  for (int i = 0; i < n; i++){
    if (v[i] < a)
      ans += v[i];
    else
      ans += a - 1;
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