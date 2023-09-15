#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
int ways[4], oldWays[4];
void test(){
  scanf("%d", &n);
  ways[1] = ways[2] = ways[3] = 1;
  for (int i = 2; i <= n; i++){
    for (int j = 0; j < 4; j++)
      oldWays[j] = ways[j], ways[j] = 0;

    for (int j = 0; j < 4; j++){
      for (int k = 0; k < 4; k++){
        if (j == k) continue;
        ways[k] = (ways[k] + oldWays[j]) % mod;
      }
    }
  }
  printf("%d\n", ways[0]);
}
int main()
{
  test();
}