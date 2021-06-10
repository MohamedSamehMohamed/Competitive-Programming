#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9; 
int n, w; 
int b[25];
void test()
{
 memset(b, 0, sizeof b); 
 scanf("%d%d", &n, &w);
 for (int i = 0; i < n; i++)
 {
  int x; scanf("%d", &x); 
  int p = 0; 
  while((1 << p) != x)p++; 
  b[p]++; 
 }
 int ans = 0; 
 while(1)
 {
  bool done = 1; 
  for (int i = 0; i < 25; i++)done &= (b[i] == 0); 
  if (done)break; 
  ans++; 
  int rem = w; 
  done = 1; 
  while(done)
  {
   done = 0; 
   for (int i = 24; i >= 0; i--)
   {
    while(b[i] && rem >= (1<<i))
    {
     done = 1; 
     b[i]--; 
     rem -= (1<<i); 
    }
   }
  }
 }
 printf("%d\n", ans); 
 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
 test();
}
