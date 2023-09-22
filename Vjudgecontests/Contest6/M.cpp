// Author : Mohamed Sameh
// created in: 9:46 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
void test(){
  scanf("%d", &n);
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++){
    v[i] = vector<int>(2);
    scanf("%d%d", &v[i][0], &v[i][1]);
  }
  sort(v.begin(), v.end(), [](vector<int>&A, vector<int>&B){
    return A[0] < B[0];
  });
  long long l = 1, r = 1e9 + 100, m, ans = 0;
  while (l <= r){
    m = (l+r) >> 1LL;
    int mn = 2e9;
    int mx = -2e9;
    int j = 0;
    bool can = 0;
    for (int i = 0; i < n; i++){
      while (j < i && v[i][0] - v[j][0] >= m)
      {
        mn = min(mn, v[j][1]);
        mx = max(mx, v[j][1]);
        j++;
      }
      if (v[i][1] - mn >= m || mx - v[i][1] >= m){
        can = 1;
        break;
      }
    }
    if (can)
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  printf("%lld\n", ans);
}
int main()
{
  test();
}