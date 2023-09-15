#include<bits/stdc++.h>
using namespace std;
long long n, m, x;
void test()
{
 scanf("%lld%lld%lld", &n, &m, &x);
 long long row = x % n; 
 if (row == 0)row = n; 
 long long col = (x+n-1) / n; 
 printf("%lld\n", (row-1) * m + col);   
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
