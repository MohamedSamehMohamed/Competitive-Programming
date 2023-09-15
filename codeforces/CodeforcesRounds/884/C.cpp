#include<bits/stdc++.h>
using namespace std;
long long sum[2];
int n, x;
void test(){
  scanf("%d", &n);
  sum[0] = sum[1] = 0;
  long long mx;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    if (i == 0) mx = x;
    sum[i % 2] += max(0, x);
    mx = max(mx, 1LL*x);
  }
  if (max(sum[0], sum[1]) != 0)
    mx = max(sum[0], sum[1]);
  printf("%lld\n", mx);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}