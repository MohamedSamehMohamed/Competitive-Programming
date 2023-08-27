// Author : Mohamed Sameh
// created in: 4:33 PM
#include <bits/stdc++.h>
using namespace std;
int a, b, n;
void test(){
  scanf("%d%d%d", &a, &b, &n);
  vector<int> ans;
  ans.push_back(b);
  for (int i = 0; i < n-2; i++){
    ans.push_back(ans.back() - i - 1);
  }
  ans.push_back(a);
  reverse(ans.begin(), ans.end());
  bool ok = 1;
  int lst = 1e9;
  for (int i = 0; i < n-1; i++){
    if (ans[i+1] <= ans[i]){
      ok = 0;
      break;
    }
    if (ans[i+1] - ans[i] >= lst){
      ok = 0;
      break;
    }
    lst = ans[i+1] - ans[i];
  }
  if (ok){
    for (int i = 0; i < n; i++)
      printf("%d ", ans[i]);
    printf("\n");
  }else
    printf("-1\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}