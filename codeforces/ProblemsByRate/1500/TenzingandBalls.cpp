#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int dp[N], a[N], best[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int i = 1; i <= n; i++)
    best[a[i]] = N;
  dp[0] =  0;
  for (int i = 1; i <= n; i++){
    dp[i] = min(dp[i-1] + 1, best[a[i]]);
    // best[a[i]] -> min(dp[j]) where a[j+1] = a[i] and j < i
    // because we delete [j+1: i] subarray  and remining is [1:j] 
    best[a[i]] = min(best[a[i]], dp[i-1]);
  }
  printf("%d\n", n - dp[n]);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}