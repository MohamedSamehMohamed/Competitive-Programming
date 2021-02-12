// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
char x[N];
int a[N], n, k;
int f1[26], f2[26], gap[N];
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
 {
  scanf("%d", &k);
  for (int i = 0; i < k; i++)
   scanf("%d", a+i); 
  
  scanf(" %s", x); 
  n = strlen(x);
  int ans = 0;
  memset(gap, 0, n * sizeof gap[0]); 
  for (int i = 0; i < k; i++)
  {
   a[i]--;
   memset(f1, 0, sizeof f1);
   memset(f2, 0, sizeof f2);
   for (int j = a[i]+1; j < n; j++)
   {
    f2[x[j]-'a'] = 1;
    if (gap[j])break; 
   }
   for (int j = a[i]; !gap[j] && j >= 0; j--)
   {
    f1[x[j]-'a'] = 1;
   }
   for (int j = 0; j < 26; j++)
    ans += (f1[j] != f2[j]); 
   gap[a[i]]=1;
  }
  printf("%d\n", ans);
 }
}
