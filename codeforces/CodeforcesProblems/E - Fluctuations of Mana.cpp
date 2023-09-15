#include <bits/stdc++.h>
 
using namespace std;
const int N = 5e5 + 9;
int n;
int a[N]; 
bool can(long long cur)
{
 for (int i = 0; i < n; i++)
 {
  cur += a[i];
  if (cur < 0)
   return 0; 
 }
return 1;
}
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i);
 long long l = 0, r = 1e16, m, ans = 0;
 while(l <= r)
 {
  m = (l+r)>>1LL;
  if (can(m))
  {
   ans = m; 
   r = m-1; 
  }else 
  l = m+1; 
 }
 printf("%lld\n", ans);
}
