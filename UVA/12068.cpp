// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int a[10], n, C = 1; 
void test()
{
 scanf("%d", &n);
 long long l = 1; 
 for (int i = 0, x; i < n; i++)
 {
  scanf("%d", &x);
  l = l/__gcd(1LL*x, l) * x; 
  a[i] = x; 
 }
 long long A = l*n;
 long long B = 0;
 for (int i = 0; i < n; i++) B+= l/a[i];  
 long long g = __gcd(A, B);
 A/= g;
 B/= g; 
 printf("Case %d: %lld/%lld\n", C++, A, B); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
