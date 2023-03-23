// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std; 
int a[1001], frq[2001], n; 
void test()
{
 memset(frq, 0, sizeof frq);
 int correct = 0; 
 scanf("%d", &n);
 int mx1, mx2, mx;
 mx1 = mx2 = mx = 0;
 for (int i = 0; i < n; i++)
 {
  scanf("%d", a+i);
  frq[a[i]]++;
  if (a[i] >= mx1)
  {
   mx2 = mx1;
   mx1 = a[i]; 
  }else 
  mx2 = max(mx2, a[i]);
 }
 mx = mx1 + mx2; 
 for (int i = 0; i < n; i++)
 {
  frq[a[i]]--; 
  int need = mx - a[i]; 
  correct += frq[need]; 
 }
 printf("%.9f\n", 1.0*correct/((n*(n-1))/2)); 
 
}
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
  test();
}
