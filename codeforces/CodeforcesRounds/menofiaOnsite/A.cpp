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
  vector<int> a(3);
  for (int i = 0; i < 3; i++)scanf("%d", &a[i]);
  for (int i = 0; i < 3; i++)
  {
    if (a[i] != a[(i-1+3) % 3] && a[i] != a[(i+1)%3])
    {
      printf("%c\n", 'A' + i);
      return;
    }
  }
  printf("*\n");
}
int main()
{
  read_file();
  test();
}
