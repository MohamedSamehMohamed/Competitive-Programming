// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
char x[22];
int C, frq[26], a[21]; 
// ans is n! / frq each character 

void test()
{
 memset(frq, 0, sizeof frq);
 memset(a, 0, sizeof a);  
 scanf(" %s", x);
 unsigned long long ans = 1;
 int n = strlen(x); 
 for (int i = 0; i < n; i++)
  frq[x[i]-'A']++;
 for (int i = 0; i < 26; i++)
  for (int j = 1; j <= frq[i]; j++)
   a[j]++;
 for (int i = n; i > 1; i--)
 {
  ans *= i;
  for (int j = 1; j <= 20; j++)
   while(a[j] && ans % j == 0) ans /= j, a[j]--; 
 }
 printf("Data set %d: %llu\n", ++C, ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
