// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int n, m; 
void test()
{
 scanf("%d%d", &n, &m);
 bool even = 0;
 for (int i = 0; i < n; i++)
  for (int j = 0, even = i%2; j < m; j++)
  {
   int x; scanf("%d", &x);
   if (even)
    x += (x&1); 
   else 
    x += !(x&1);
   even ^= 1; 
   printf("%d%c", x, (j+1==m? '\n': ' ')); 
  }
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test();
}
