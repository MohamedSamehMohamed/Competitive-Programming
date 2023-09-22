// Author : Mohamed Sameh
// created in: 7:28 PM
#include <bits/stdc++.h>
using namespace std;
bool prime(int x){
  if (x < 2) return 0;
  for (int i = 2; i <= x/i; i++)
    if (x % i == 0)return 0;
  return 1;
}
void test(){
  vector<int> take;
  map<int, int> mp;
  for (int i = 2; i <= 50; i++){
    if (prime(i))
    {
      take.push_back(i);
      mp[i] = take.size()-1;
    }
  }
  long long ans = 1e18;
  int sz = take.size();
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }

  vector<vector<int>> factors(n);
  for (int i = 0; i < n; i++){
    for (int j = 2; j <= v[i]; j++){
      if (v[i] % j) continue;
      while (v[i] % j == 0){
        v[i] /= j;
      }
      factors[i].push_back(mp[j]);
    }
    if (v[i] != 1){
      factors[i].push_back(mp[v[i]]);
    }
  }

  for (int i = 1; i < (1<<sz); i++){
    long long current = 1;
    for (int j = 0; j < sz; j++){
      if (i & (1<<j))
        current *= take[j];
    }
    bool ok = 1;
    for (int j = 0; j < n; j++){
      bool pass = 0;
      for (int k: factors[j]){
        if (i & (1<<k)){
          pass = 1;
          break;
        }
      }
      if (!pass){
        ok = 0;
        break;
      }
    }
    if (ok) ans = min(ans, current);
  }
  printf("%lld\n", ans);
}
int main()
{
  test();
}