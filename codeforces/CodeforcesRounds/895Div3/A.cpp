// Author : Mohamed Sameh
// created in: 4:21 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int ans = 0;
  int tar = (a+b+1) / 2;
  if (min(a, b) < tar){
    ans += (tar - min(a, b)) / c;
    if (min(a, b) + c * ans < tar)
      ans++;
  }
  printf("%d\n", ans);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}