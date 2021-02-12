// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, m; 
void test()
{
 scanf("%d%d", &n, &m);
 if ((__gcd(n, m) == n) && (n/__gcd(n, m) * m) == m)
  printf("%d %d\n", n, m);
 else 
  printf("-1\n"); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
