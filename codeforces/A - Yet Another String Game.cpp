// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
char x[60];
void test()
{
 scanf(" %s", x);
 int n = strlen(x);
 for (int i = 0; i < n; i++)
 {
  if (i % 2 == 0)
  {
   if (x[i] != 'a')x[i] = 'a'; 
   else x[i] = 'b'; 
  }else 
  {
   if (x[i] != 'z')x[i] = 'z'; 
   else x[i] = 'y'; 
  }
 }
 printf("%s\n", x); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
