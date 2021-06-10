#include<bits/stdc++.h>
using namespace std;
char x[30], y[30]; 
int n, m;
int solve(int sx, int sy)
{
 int sz = 0;
 while(sx < n && sy < m && x[sx] == y[sy])
 {
  sz+=2; 
  sx++;
  sy++; 
 }
 return n + m - sz; 
}
void test()
{
 scanf(" %s", x);
 scanf(" %s", y);
 n = strlen(x);
 m = strlen(y);
 int op = 1e9; 
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < m; j++)
  {
   op = min(op, solve(i, j));
  }
 }
 printf("%d\n", op); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
