// Author : Mohamed Sameh
// created in: 4:47 PM
#include <bits/stdc++.h>
using namespace std;
int n, x;
void test(){
  scanf("%d%d", &n, &x);
  int need = 0;
  bool same = 1;
  bool allGood = 1;
  for (int i = 0; i < n; i++){
    int val;
    scanf("%d", &val);
    same &= (val == x);
    need += (x - val);
    allGood &= (val != x);
  }
  /*
   * 2
   * 1 2
   */
  if (same)
    printf("0\n");
  else if (need == 0 || !allGood)
    printf("1\n");
  else
    printf("2\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}