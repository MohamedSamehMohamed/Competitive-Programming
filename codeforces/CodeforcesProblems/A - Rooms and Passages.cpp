// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 9;
int a[N];
int ans[N];
map<int, int> lst;
int n;
int lstidx(int x)
{
  if (lst.find(x) == lst.end())
    return n;
  return lst[x];
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  ans[n-1] = 1;
  lst[a[n-1]] = n-1;
  for (int i = n-2; i > -1; i--)
  {
    if (a[i] > 0)
      ans[i] = 1 + ans[i+1];
    else
      ans[i] = min(1 + ans[i+1], lstidx(-a[i]) - i);
    lst[a[i]] = i;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
  printf("\n");
}
