// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n; 
 while(scanf("%d", &n) && n >= 0)
 {
  printf("%lld\n", (1LL*n * (n+1))/2 + 1); 
 }
}
