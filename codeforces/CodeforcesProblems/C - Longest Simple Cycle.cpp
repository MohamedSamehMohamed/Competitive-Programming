// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], b[N], c[N], n;
long long best[N];
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)best[i] = 0;
 for (int i = 0; i < n; i++)
  scanf("%d", c+i);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i);
 for (int i = 0; i < n; i++)
  scanf("%d", b+i);
 long long ans = 0;
 for (int i = 1; i < n; i++)
 {
  int cur = abs(a[i] - b[i]);
  long long len = 1LL*c[i] + 1 + cur;
  long long ff = 1LL + c[i] + (a[i]-1) + (c[i-1]-b[i]) + best[i-1] - (c[i-1]-1);  
  if (i == 1)ff = 0;
  
  if (a[i] > b[i])
  {
   ff -= (a[i]-1) + (c[i-1]-b[i]); 
   ff += (c[i-1]-a[i]) + (b[i]-1); 
  }
  if (a[i] == b[i])ff = 0;
  best[i] = max(len, ff); 
  ans = max(ans, best[i]);
 }
 //for (int i = 0; i < n; i++)cout << best[i] <<" ";cout <<"\n"; 
 printf("%lld\n", ans); 
 
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
   test();
   
}
