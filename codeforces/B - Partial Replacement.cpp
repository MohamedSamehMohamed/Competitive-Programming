#include<bits/stdc++.h>
using namespace std;
int n, k;
char x[100]; 
void test()
{
 scanf("%d%d %s", &n, &k, x);
 int ans = 0;
 int i = 0, j = n-1;
 while(i < n && x[i] != '*')
  i++; 
 while(j >= 0 && x[j] != '*')
  j--; 
 ans++;
 if (i != j)ans++; 
 for (;i < j;)
 {
  int nxt = i + k;
  if (nxt >= j)break; 
  while(nxt >= i && x[nxt] != '*')
  {
   nxt--; 
  }
  ans++; 
  i = nxt; 
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
