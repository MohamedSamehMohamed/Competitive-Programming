// Author : Mohamed Sameh
// created in: 3:59 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int a[N], n;
void test(){
  scanf("%d", &n);
  int xo = 0;
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
    xo ^= a[i];
  }
  vector<vector<int>> ans;
  ans.push_back({1, n});
  if (xo != 0){
    if (n % 2 == 0){
      ans.push_back({1, n});
    }else {
      ans.push_back({1, 2});
      ans.push_back({2, 3});
      ans.push_back({1, n});
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto i: ans){
    printf("%d %d\n", i[0], i[1]);
  }

}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}