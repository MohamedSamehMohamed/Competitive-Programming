#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n, a[2009];
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a+i);
  int ans = 0;
  if (n == 1)
  {
    printf("0\n");
    return;
  }
  int mx = -1, mn = 1e9;
  for (int i = 0; i < n; i++)
  {
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
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