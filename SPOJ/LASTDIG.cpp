// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a, b, t;
 scanf("%d", &t);  
 while (t--)
 {
  scanf("%d%d", &a, &b); 
  a = a % 10; 
  int ret = 1;
  while(b)
  {
   if (b&1) ret = ret * a; 
   a = a * a;  
   b >>= 1; 
   a = a % 10; 
   ret = ret % 10; 
  }
  printf("%d\n", ret); 
 }
}
