// Author : Mohamed Sameh
// created in: 8:22 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 45, inf = 100;
int n, a, b;
char s[N];
int dp[N][N][N][N];
int val(int i){
  return s[i] - '0';
}
int solve(int i = 0, int atk = 0, int btk = 0, int suma = 0, int sumb = 0){
  suma %= a;
  sumb %= b;
  if (i == n){
    if(suma == 0 && sumb == 0 && min(atk, btk) > 0)
      return abs(atk - btk);
    return inf;
  }
  int& ret = dp[i][atk][suma][sumb];
  if(~ret) return ret;
  int sol1 = solve(i+1, atk + 1, btk, suma * 10 + val(i), sumb);
  int sol2 = solve(i+1, atk, btk + 1, suma, sumb * 10 + val(i));
  ret = min(sol1, sol2);
  return ret;
}
void build(int i = 0, int atk = 0, int btk = 0, int suma = 0, int sumb = 0){
  suma %= a;
  sumb %= b;
  if (i == n){
    return;
  }
  int ret = dp[i][atk][suma][sumb];
  int sol1 = solve(i+1, atk + 1, btk, suma * 10 + val(i), sumb);
  if (ret == sol1){
    printf("R");
    build(i+1, atk + 1, btk, suma * 10 + val(i), sumb);
  }else {
    printf("B");
    build(i+1, atk, btk + 1, suma, sumb * 10 + val(i));
  }
}
void test(){
  scanf("%d%d%d %s", &n, &a, &b, s);
  memset(dp, -1, sizeof dp);
  if (solve() < inf)
    build();
  else
    printf("-1");
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}