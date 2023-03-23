// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int p, q, r, s, t, u; 
double solve(double x)
{
 return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u; 
}
int main()
{ 
 while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6)
 {
  double l = 0, r = 1;
  while(r-l >= 1e-9)
  {
   double m = (l+r)/2.0; 
   double s1 = solve(m); 
   if (s1 >= 0)
    l = m; 
   else 
    r = m; 
  } 
  if (fabs(solve((r+l)/2.0)) > 1e-4)
   printf("No solution\n"); 
  else 
   printf("%.4f\n", (r+l)/2.0); 
 }
}
