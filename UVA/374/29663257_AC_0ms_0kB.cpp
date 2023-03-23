// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a, b, m; 
 while (~scanf ("%d%d%d" , &a , &b ,&m ))
 {
  int ret = 1;
  while(b)
  {
   if (b&1) ret = (1LL * ret * a) % m; 
   a = (1LL * a * a) % m; 
   b >>= 1; 
  }
  printf("%d\n", ret); 
 }
}
