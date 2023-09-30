// Author : Mohamed Sameh
// created in: 1:45 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int k[N], h[N], n;
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", k+i);
  for (int i = 0; i < n; i++)
    scanf("%d", h+i);
  vector<vector<int>> ranges;
  for (int i = 0; i < n; i++){
    ranges.push_back({k[i]-h[i]+1, k[i]});
  }
  sort(ranges.begin(), ranges.end());
  long long ans = 0;
  stack<vector<int>> stk;
  stk.push(ranges[0]);
  for (int i = 1; i < ranges.size(); i++){
    if (ranges[i][0] > stk.top()[1])
      stk.push(ranges[i]);
    else
      stk.top()[1] = max(stk.top()[1], ranges[i][1]);
  }
  while (!stk.empty()){
    auto cur = stk.top();stk.pop();
    int len = cur[1] - cur[0] + 1;
    ans += 1LL * (len+1) * (len) / 2;
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}