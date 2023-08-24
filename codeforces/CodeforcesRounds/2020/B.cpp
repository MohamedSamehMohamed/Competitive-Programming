// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 8;
int a[N], n;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    for (int i = 0; i < n; i++)
    {
      int j = i+1;
      while(j < n && a[j] == a[i])
        j++;
      j--;
      if (i == j)
      {
        if (i-1>=0&&a[i]==a[i-1])a[i]++;
        continue;
      }
      a[j]++;
      i = j;
    }
    int ans = 0;
    sort(a, a+n);
    for (int i = 0; i < n; i++)
    {
      ans++;
      int j = i+1;
      while(j < n && a[j] == a[i])
        j++;
      i = j-1;
    }
    printf("%d\n", ans);
  }
}
