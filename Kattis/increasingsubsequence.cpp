// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 201;
int a[N], dp[N], nxt[N], n; 
void test()
{
 for (int i = 0; i < n; i++)
  scanf("%d", a+i); 
 for (int i = n-1; ~i; i--)
 {
  dp[i] = 1; 
  nxt[i] = i; 
  for (int j = i+1; j < n; j++)
  {
   if (a[i] < a[j])
   {
    if ((dp[j] + 1 > dp[i]) || ((dp[j] + 1 == dp[i]) && a[j] < a[nxt[i]]))
    dp[i] = dp[j] + 1, nxt[i] = j; 
   }
  }
 }
 int st = 0;
 for (int i = 0; i < n; i++)
 if (dp[i] > dp[st] || (dp[i] == dp[st] && a[i] < a[st]))
  st = i; 
 printf("%d", dp[st]);
 while(st != nxt[st])
  printf(" %d", a[st]), st = nxt[st]; 
 printf(" %d\n", a[st]); 
}
int main()
{
 while(scanf("%d", &n) && n)
  test(); 
}
