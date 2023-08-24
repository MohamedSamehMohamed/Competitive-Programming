#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
char x[1000009];
int n;
void test()
{
  scanf(" %s", x);
  n = strlen(x);
  if (n == 1 && x[0] == '1')
  {
    printf("0\n");
    return;
  }
  int ans = 0;
  for(int i = n-1; i >= 0; i--)
  {
    if (x[i] == '0')
    {
      ans++; 
    }else 
    {
      if (i == 0)break;
      int j = i-1;
      while(j >= 0 && x[j]=='1')
        j--;
      int len = i - j; 
      // printf("%d\n", len); 
      ans += len + 1;
      if (j >= 0)
      {
        x[j] = '1';
      }
      i = j + 1; 
    }
  }
  printf("%d\n", ans);
}
int main()
{
  read_file();
  int t;
  t = 1;
  while(t--)
    test();
}
