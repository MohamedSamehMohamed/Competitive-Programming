// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
string Find(int x, int y, int a = 0, int b = 1, int c = 1, int d = 0)
{
 int m = a + c;
 int n = b + d; 
 if (m == x && n == y)return "";
 if (x * n < y * m) 
  return "L" + Find(x, y, a, b, m, n); 
 else 
  return "R" + Find(x, y, m, n, c, d); 
} 
int main()
{
 int n, m;
 while(scanf("%d%d", &m, &n) && (n+m!=2))
 {
  printf("%s\n", Find(m, n).c_str()); 
 } 
}

