// Author : Mohamed Sameh
// created in: 5:04 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long dp[N];
int n, a[N];
int frq[N];
long long solve(int mex){
  if (mex == 0) return 0;
  long long& ret = dp[mex];
  if (~ret) return ret;
  ret = n * mex;
  for (int i = 0; i < mex; i++){
    ret = min(ret, (frq[i] - 1) * mex + i + solve(i));
  }
  return ret;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i <= n; i++){
    frq[i] = 0;
    dp[i] = -1;
  }
  for (int i = 0; i < n; i++)scanf("%d", a+i);
  for (int i = 0; i < n; i++){
    if (a[i] <= n) frq[a[i]]++;
  }
  int mex = 0;
  while (frq[mex] > 0) mex++;
  if (mex == 0){
    printf("0\n");
    return;
  }
  printf("%lld\n", solve(mex));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}