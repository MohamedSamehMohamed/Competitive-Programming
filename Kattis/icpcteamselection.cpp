// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, a[301]; 
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < 3 * n; i++)
  scanf("%d", a+i); 
 sort(a, a+3*n);
 int ans = 0; 
 for (int i = 3*n - 2, c = 0; c++ < n; i-=2)
   ans += a[i]; 
 printf("%d\n", ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
