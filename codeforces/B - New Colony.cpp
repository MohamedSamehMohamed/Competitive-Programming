// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 104;
int a[N], n, k;
void test()
{
 scanf("%d%d", &n, &k);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i);
 int ans = -1; 
 while(k--)
 {
  int p = 0;
  while(p + 1 < n && a[p] >= a[p+1])
   p++; 
  if (p == n-1)
  {
   ans = -1;break; 
  }else 
  {
   ans = p+1;
   a[p]++;
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
