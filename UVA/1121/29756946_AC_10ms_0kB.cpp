#include<bits/stdc++.h>
const int N = 1e5 + 9;
int a[N], n, m;
bool can(int len)
{
 int sum = 0;
 for (int i = 0; i < len-1; i++)sum += a[i];
 for (int i = 0, j = len-1; j < n; i++, j++)
 {
  sum += a[j]; 
  if (sum >= m)return 1;
  sum -= a[i]; 
 }
 return 0; 
}
int main()
{
 while(~scanf("%d%d", &n, &m))
 {
  for (int i = 0; i < n; i++)
   scanf("%d", a+i); 
  int l = 1, r = n, ans = 0;
  while(l <= r)
  {
   int mid = (l+r) >> 1;
   if (can(mid))
    ans = mid, r = mid - 1;
   else 
    l = mid + 1; 
  }
  printf("%d\n", ans); 
 }
}
