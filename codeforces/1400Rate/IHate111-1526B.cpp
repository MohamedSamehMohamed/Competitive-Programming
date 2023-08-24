#include <bits/stdc++.h>
using namespace std;
int n;
void test(){
  scanf("%d", &n);
  for (int i = 0; (n-(i*111)) >= 0 && i < 11; i++){
    if ((n-(i * 111)) % 11 == 0)
    {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}