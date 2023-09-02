// Author : Mohamed Sameh
// created in: 6:46 PM
#include <bits/stdc++.h>
using namespace std;
char c[11];
void test(){
  scanf(" %s", c);
  for (int i = 0; i < 9; i++)
  {
    if (c[i] == '1'){
      printf("13\n");
      return;
    }else if (c[i] == '3'){
      printf("31\n");
      return;
    }
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}