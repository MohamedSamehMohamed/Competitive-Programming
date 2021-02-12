// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int x, y;
double cal(double h)
{
 return 1.0*(x-2.0*h) * (y-2.0*h) * h; 
}
void test()
{
 scanf("%d%d", &x, &y); 
 double l = 0.000001, r = min(x, y)/ 2.0, ebs = 1e-6;
 while(r - l > ebs)
 {
  double m1 = l + (r-l)/3;
  double m2 = r - (r-l)/3;
  double a1 = cal(m1);
  double a2 = cal(m2);
  if (a1 < a2)
   l = m1;
  else 
   r = m2; 
 }
 printf("%.11f\n", cal(r)); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
