#include<bits/stdc++.h>
using namespace std;
double v[101]; 
double solve(int lst)
{
 double tot = 0;
 for (int i = 0; i <= lst; i++)
 {
  double cur = v[i]; 
  for (int j = 0; j <= lst; j++)
   if (j != i)
    cur *= 1 - v[j]; 
  tot += cur; 
 }
 return tot; 
}
int main()
{
 int n;
 scanf("%d", &n);
 double ans = 0; 
 for (int i = 0; i < n; i++)
 {
  scanf("%lf", &v[i]); 
  ans = max(ans, v[i]); 
 }
 sort(v, v+n);
 for (int i = 0; i < n-i-1; i++)swap(v[i], v[n-i-1]);  
 for (int i = 0; i < n; i++)
  ans = max(ans, solve(i));
 printf("%.12lf\n", ans); 
}
