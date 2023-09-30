// Author : Mohamed Sameh
// created in: 8:40 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int a[N], n;
long long ans;
vector<int> v;
void solve(int i = 0){
  if (i == n){
    long long cur = 0;
    for (int j: v)
      cur ^= j;
    ans = min(ans, cur);
    return;
  }
  int cur = 0;
  while (i < n){
    cur|=a[i];
    v.push_back(cur);
    solve(i+1);
    v.pop_back();
    i++;
  }
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  ans = 2e9;
  solve();
  printf("%d\n", ans);
}
int main()
{
  test();
}