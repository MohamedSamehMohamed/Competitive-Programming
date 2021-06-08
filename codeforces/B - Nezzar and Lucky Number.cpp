// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int a[N], n, d;
bool contain(int x)
{
 if (x == 0)return 1; 
 while(x)
 {
  int c = x % 10;
  if (c == d)return 1; 
  x /= 10;
 }
 return 0; 
} 
void solve(int x)
{
  if (contain(x))
  {
   printf("YES\n");
   return; 
  }
  for (int i = 1; i <= x/d; i++)
  {
   if (contain(x-(i*d)))
   {
     printf("YES\n"); 
     return;
   }
  } 
  printf("NO\n"); 
}
void test()
{
 scanf("%d%d", &n, &d);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i);
 for (int i = 0; i < n; i++)
 {
  solve(a[i]); 
 }
}
int main()
{
  int t; 
  scanf("%d", &t);
  while(t--)
   test();
}
