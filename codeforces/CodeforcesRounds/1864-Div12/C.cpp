// Author : Mohamed Sameh
// created in: 6:48 PM
#include <bits/stdc++.h>
using namespace std;
/*
 * n = a + b + c + ...+ 1
 * a|n, b|a, c|b... (a, b, c, ...)| n
 *
 */
int n;
void test(){
  scanf("%d", &n);
  vector<int> ans;
  ans.push_back(n);
  for (int i = 0; n > 2 && i <= 30 && n > (1<<i); i++){
    if (n & (1<<i)){
      n -= (1<<i);
      ans.push_back(n);
    }
  }
  while (n != 1){
    if (n % 2 == 0){
      n -= n / 2;
      ans.push_back(n);
    }else {
      ans.push_back(n-1);
      n--;
    }
  }
  printf("%d\n", ans.size());
  for (int i: ans)printf("%d ", i);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}