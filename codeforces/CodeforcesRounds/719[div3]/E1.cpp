#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
char x[N];
int n;
void test()
{
  scanf("%d", &n);
  scanf("%s", x);
  int sheep = 0;
  for (int i = 0; i < n; i++)sheep += (x[i] == '*');
  if (sheep == 0 || sheep == n)
  {
    printf("0\n");
    return;
  }

  long long ans = 1e18;
  for (int i = 0; i < n; i++)
  {
    ***.**
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
