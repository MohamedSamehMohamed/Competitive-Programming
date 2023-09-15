#include<bits/stdc++.h>
using namespace std;
int a, b;
void solve(){
  scanf("%d%d", &a, &b);
  int ans = a+b;
  for (int i = 1; i <= (int)1e5; i++)
    ans = min(ans, (a+i-1) / i + (b+i-1) / i + i - 1);
  printf("%d\n", ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}