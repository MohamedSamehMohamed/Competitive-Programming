// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long A, B, x1, x2, Y1, Y2; 
int n; 
char op;
void solveAdd()
{
 B = Y1/__gcd(Y1, Y2) * Y2; 
 A = (B/Y1 * x1) + (B/Y2 * x2);
 long long g = __gcd(A, B); 
 A/= g;
 B/= g; 
} 
void solveMul()
{
 A = x1 * x2;
 B = Y1 * Y2; 
 long long g = __gcd(A, B);
 A/= g;
 B/= g; 
}
int main()
{
 scanf("%d", &n);
 while(n--)
 {
  scanf("%lld%lld %c%lld%lld", &x1, &Y1, &op, &x2, &Y2); 
  if (op == '-') x2 *= -1; 
  if (op == '/') swap(x2, Y2); 
  if (op == '+' || op == '-')
   solveAdd();
  else 
   solveMul(); 
  if (B < 0) A *= -1, B *= -1;
  printf("%lld / %lld\n", A, B);
 }
}
