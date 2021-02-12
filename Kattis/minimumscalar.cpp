// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 801; 
int n, a[N], b[N], Case; 
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)scanf("%d", a+i); 
 for (int i = 0; i < n; i++)scanf("%d", b+i);
 sort(a, a+n);
 sort(b, b+n); 
 long long ans = 0;
 for (int i = 0; i < n; i++)
   ans += 1LL*a[i] * b[n-i-1]; 
 printf("Case #%d: %lld\n", ++Case, ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
