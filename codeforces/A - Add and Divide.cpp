// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int a, b;
void test()
{
 scanf("%d%d", &a, &b);
 int ans = 2e9;
 for (int i = 0; i < 100; i++)
 {
  int curb = b + i;
  int cura = a; 
  int curans = i;
  while(cura != 0 && cura/curb != cura)
  {
   curans++;
   cura=cura/curb; 
  }
  if (cura)continue;
  ans = min(ans, curans);
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
