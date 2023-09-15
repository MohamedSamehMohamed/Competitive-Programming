// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, px, py;
char x[N]; 
void test()
{
 scanf("%d%d", &px, &py);
 scanf(" %s", x);
 n = strlen(x);
 int cpx = 0, cpy = 0;
 int R, D, U, L;
 R = D = U = L = 0;
 for (int i = 0; i < n; i++)
 {
  if (x[i] == 'U')cpy++, U++;
  else if (x[i] == 'D')cpy--, D++;
  else if (x[i] == 'R')cpx++, R++;
  else 
  cpx--, L++; 
 }
 bool ok = 1;
 if (px < 0)
 {
  if (L < -px) ok = 0;
 }
 else if (px > 0)
 {
  if (R < px) ok = 0;
 }
 
 if (py < 0)
 {
  if (D < -py)ok = 0;
 }
 else if (py > 0)
 {
   if (U < py)ok = 0;
 }
 if (ok)
  printf("YES\n"); 
 else 
  printf("NO\n");
 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
