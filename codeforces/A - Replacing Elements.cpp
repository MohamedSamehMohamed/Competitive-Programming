// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 101;
int a[N], n, d;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    sort(a, a+n);
    if ((a[0] + a[1] <= d) || a[n-1] <= d)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
