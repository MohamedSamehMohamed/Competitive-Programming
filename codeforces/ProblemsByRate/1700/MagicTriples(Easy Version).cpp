#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, MAX = 1e3;
int a[N], n;
void solve(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
  }
  map<int, int> cnt;
  for (int i = 0; i < n; i++)
    cnt[a[i]]++;
  long long ans = 0;
  auto calc = [&](int a, int b, int c){
    if (cnt.count(a) == 0) return;
    if (cnt.count(b) == 0) return;
    if (cnt.count(c) == 0) return;
    ans += 1LL * cnt[a] * cnt[b] * cnt[c];
  };
  
  for(auto cur: cnt){
   if (cur.second > 2)
    {
      ans += 1LL * cur.second * (cur.second - 1) * (cur.second - 2);
    }
   if (cur.first > MAX * MAX){
    for (int d = 2; 1LL * d * cur.first <=  MAX * MAX * MAX; d++){
      if (cur.first % d == 0)
        calc(cur.first / d, cur.first, cur.first * d);
    }
   }else {
    for (int d = 2; d <= cur.first / d; d++){
      if (cur.first % d == 0 && 1LL * cur.first * d <= MAX * MAX * MAX)
        calc(cur.first / d, cur.first, cur.first * d);
      int sd = cur.first / d;
      if (sd != d && cur.first % sd == 0 && 1LL * cur.first * sd <= MAX * MAX * MAX)
        calc(cur.first / sd, cur.first, cur.first * sd);
    }
   }
   if (cur.first > 1 && 1LL * cur.first * cur.first <= MAX * MAX * MAX)
    calc(1, cur.first, cur.first * cur.first);
  }
  printf("%lld\n", ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}