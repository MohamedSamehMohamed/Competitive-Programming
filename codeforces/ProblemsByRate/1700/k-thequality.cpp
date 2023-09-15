#include<bits/stdc++.h>
using namespace std;
int a, b, c;
long long k;
int power(int p){
  int cur = 1;
  while (p){
    cur *= 10;
    p--;
  }
  return cur;
}
void solve(){
  scanf("%d%d%d%lld", &a, &b, &c, &k);
  int minA = power(a-1), maxA = power(a);
  for (int cur = minA; cur < maxA; cur++){
    int minB = max(power(b-1), power(c-1) - cur);
    int maxB = min(power(b) - 1, power(c) - 1 - cur);
    if (minB > maxB) continue;
    int cnt = maxB - minB + 1;
    if (k > cnt)
    {
      k -= cnt;
      continue;
    }
    int bValue = minB + k - 1;
    printf("%d + %d = %d\n", cur, bValue, cur + bValue);
    return;
  }
  printf("-1\n");
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}
