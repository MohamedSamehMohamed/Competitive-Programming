// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n;
double p; 
int main()
{
 scanf("%d%lf", &n, &p);
 // P(n) = 1/2 * (1 + (1-2p)^n)
 double ans = 1, sc = 1 - 2 * p;
 while(n)
 {
  if (n&1) ans = (ans*sc); 
  n >>= 1; 
  sc = sc * sc; 
 }
 ans += 1; 
 printf("%.10lf\n", ans/2.0); 
}
