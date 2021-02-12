// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 10e3 + 9;
int a[N], b[N], n;
bool between;   
void test()
{
 if (between)printf("\n"); 
 between = 1;
 for (int i = 0; i < 2 * n; i++)
  scanf("%d", a+i), b[i] = a[i];
 sort(a+n, a+2*n);
 sort(a, a+n); 
 for (int i = 0; i < n; i++)
 {
  int l = 0, r = n-1, idx = -1;
  while(l <= r)
  {
   int m = (l+r)>>1;
   if (a[m] == b[i])
   {
    idx = m;break;
   }
   if (a[m] < b[i])
    l = m + 1; 
   else 
    r = m - 1; 
  }
  b[i+n] = a[n+idx]; 
 }
 for (int i = n; i < 2 * n; i++)
  printf("%d\n", b[i]); 
}
int main()
{
 while(scanf("%d", &n) && n)
  test(); 
}
