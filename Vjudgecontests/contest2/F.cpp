// Author : Mohamed Sameh
// created in: 9:35 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(m);
  for (int i = 0; i < m; i++)
    scanf("%d", &a[i]);
  a.push_back(0);
  a.push_back(n+1);
  sort(a.begin(), a.end());
  int mn = 1e9;
  vector<int> v;
  for (int i = 1; i < a.size(); i++){
    if (a[i] - a[i-1] - 1 > 0) {
      mn = min(mn, a[i] - a[i - 1] - 1);
      v.push_back(a[i] - a[i - 1] - 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < v.size(); i++){
    //printf("%d ", v[i]);
    ans += (v[i] + mn-1)/mn;
  }
  printf("%d\n", ans);
}
int main()
{
  test();
}