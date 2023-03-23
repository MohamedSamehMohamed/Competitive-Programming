// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std; 
int a[1001], frq[2001], n; 
void test()
{
 memset(frq, 0, sizeof frq);
 int correct = 0; 
 scanf("%d", &n);
 for (int i = 0; i < n; i++) scanf("%d", a+i), frq[a[i]]++;
 int mx = 0;
 for (int i = 1000; i >= 1; i--)
 {
  if (!frq[i])continue; 
  if (mx)
  {
   mx += i;break; 
  }else 
  {
   if (frq[i] > 1)
   {
    mx += 2 * i;break; 
   }
   mx += i; 
  }
 }
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
