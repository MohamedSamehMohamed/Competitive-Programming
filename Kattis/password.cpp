// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std; 
int n;
vector<double> v; 
char x[13];
int main()
{
 scanf("%d", &n);
 v = vector<double> (n);
 for (double &i: v)
  scanf(" %s%lf", x, &i);
 sort(v.rbegin(), v.rend()); 
 double ans = 0; 
 for (int i = 0; i < n; i++)
 {
  ans += (i+1) * v[i];
 }
 printf("%.4lf\n", ans); 
}
