#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e5 + 9;
int a[N], n;
void test()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", a+i);
  }
  if (a[0] % 2 == 0)
  {
    printf("NO\n");
  }
  else
  { 
    bool ok = 1;
    for(int i = 0; i < n; i++)
    {
      if (a[i] % 2 || a[i] % 3)continue;
      if (i <= 1)
      {
        ok = 0;break; 
      }
      int j = i+2; 
      int cnt = 20;
      while(cnt-- && a[i] % j == 0)
      {
        j--;
        if (j == 1)break; 
      }
      if (a[i] % j)continue; 
      ok = 0;
      break; 

    }
    if (ok)
      printf("YES\n");
    else 
      printf("NO\n");  
  }
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
