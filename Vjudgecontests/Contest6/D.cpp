// Author : Mohamed Sameh
// created in: 8:52 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (1LL * i * j > n) break;
      for (int k = 1; k <= n; k++){
        if (1LL * i * j * k > n) break;
        ans++;
      }
    }
  }
  printf("%d\n", ans);
}
int main()
{
  test();
}