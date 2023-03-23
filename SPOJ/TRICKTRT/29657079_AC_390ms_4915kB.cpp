// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 9;
float a[N][2]; 
int n;
double dist(int i, double x)
{
 return sqrt(pow(a[i][0] - x, 2) + pow(a[i][1], 2)); 
}
double solve(double d)
{
 double tot = 0;
 for (int i = 0; i < n; i++)
 {
  tot = max(tot, dist(i, d)); 
 }
 return tot; 
}
void test()
{
 for (int i = 0; i < n; i++)
  scanf("%f%f", a[i], a[i]+1); 
 double l = -2e5, r = 2e5, ebs = 1e-5;
 while(r - l > ebs)
 {
  double m1 = l + (r-l)/3;
  double m2 = r - (r-l)/3;
  double d1 = solve(m1);
  double d2 = solve(m2); 
  if (d1 > d2)
   l = m1 + ebs;
  else 
   r = m2 - ebs; 
 }
 printf("%.9f %.9f\n", l, solve(l));
}
int main()
{
 while(scanf("%d", &n) && n)
  test(); 
}
