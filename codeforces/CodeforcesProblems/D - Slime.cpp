// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long ans;
int n, mn = 1e9 + 9;
int main()
{
 scanf("%d", &n);
 if (n==1)
 {
  int x; scanf("%d", &x); printf("%d\n", x); return 0;
 }
 int msk = 0;
 for (int i = 0, x; i < n; i++)
 {
  scanf("%d", &x);
  ans += abs(x);
  mn = min(mn, abs(x));
  if (x==0)msk = 3; 
  msk |= (1<<(x>=0));
 }
 if (msk != 3)
  ans -= 2 * mn; 
 printf("%lld\n", ans); 
}
