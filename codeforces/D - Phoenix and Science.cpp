#include<bits/stdc++.h>
using namespace std;
void test()
{
  int n;
  scanf("%d", &n);
  vector<int> ans;
  ans.push_back(1);
  int cur = 1;
  while(cur + 2 * ans.back() <= n)
  {
    int x = 2 * ans.back();
    cur += x;
    ans.push_back(x);
  }
  if (cur != n)
  {
    ans.push_back(n - cur);
    sort(ans.begin(), ans.end());
  }
  printf("%d\n", ans.size() - 1);
  for (int i = 1; i < ans.size(); i++)
    printf("%d ", ans[i] - ans[i-1]);
  printf("\n");
}
int main()
{
  int t;scanf("%d", &t);
  while(t--)
    test();
}
