// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int h[N], cost[N], n;
long long solve(int x)
{
 long long ret = 0;
 for (int i = 0; i < n; i++)
  ret += 1LL * abs(h[i] - x) * cost[i];
 return ret;
}
void ternary()
{
 int l = 0, r = *max_element(h, h+n); 
 while(l < r)
 {
  int m1 = l + (r-l)/3; 
  int m2 = r - (r-l)/3; 
  long long s1 = solve(m1);
  long long s2 = solve(m2);
  if (s1 > s2)
   l = m1 + 1; 
  else 
   r = m2 - 1;  
 }
 printf("%lld\n", solve(l)); 
}
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)scanf("%d", h+i); 
 for (int i = 0; i < n; i++)scanf("%d", cost+i);
 ternary();
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
