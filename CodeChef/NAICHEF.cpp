// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std; 
int n, a, b;
void test()
{
 scanf("%d%d%d", &n, &a, &b); 
 double aprob = 0, bprob = 0; 
 for (int i = 0; i < n; i++)
 {
  int x;scanf("%d", &x); 
  aprob += (x == a); 
  bprob += (x == b);
 }
 aprob /= n;
 bprob /= n; 
 printf("%.9lf\n", aprob * bprob); 
}
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
  test();
}
