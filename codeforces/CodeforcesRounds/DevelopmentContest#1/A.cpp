#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
void test()
{
  int n;
  scanf("%d", &n);
  int ans = 0;
  while(n--)
  {
    int x;scanf("%d", &x);
    int cnt = 0;
    while(x)
    {
      int d = x % 10;
      cnt += (d == 2 || d == 3 || d == 5 || d == 7);
      x/=10;
    }
    ans += (cnt > 1); 
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
