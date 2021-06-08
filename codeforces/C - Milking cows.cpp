// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n; 
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i);
 long long ans = 0;
 int zeros = 0;
 for (int i = 0; i < n; i++)
  zeros += !a[i]; 
 for(int i = 0; i < n; i++)
 {
  zeros -= !a[i];
  ans += a[i] * zeros; 
 } 
 printf("%lld\n", ans); 
}
