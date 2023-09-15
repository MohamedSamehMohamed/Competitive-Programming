// Author : Mohamed Sameh
// created in: 4:12 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, k, a, b;
int pos[N][2];
long long get_dist(int i, int j){
  return 1LL * abs(pos[i][0] - pos[j][0]) +
  1LL * abs(pos[i][1] - pos[j][1]);
}
void test(){
  scanf("%d%d%d%d", &n, &k, &a, &b);
  for (int i = 0; i < n; i++){
    scanf("%d%d", pos[i] + 0, pos[i] + 1);
  }
  if (max(a, b) <= k){
    printf("0\n");
    return;
  }
  a--;b--;
  long long ans = get_dist(a, b);
  long long mn1 = 1e14, mn2 = 1e14;
  for (int i = 0; i < k; i++){
      mn1 = min(mn1, get_dist(i, a));
      mn2 = min(mn2, get_dist(i, b));
  }
  ans = min(ans, mn1 + mn2);
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}