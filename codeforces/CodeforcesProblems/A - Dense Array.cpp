// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N], n;
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i); 
 int ans = 0; 
 for (int i = 0; i + 1 < n; i++)
 {
  int mn = min(a[i], a[i+1]);
  int mx = max(a[i], a[i+1]); 
  if (2 * mn >= mx)continue;
  while(2 * mn < mx)
  {
   mn = 2 * mn;
   ans++;
  }
 }
 printf("%d\n", ans);
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
