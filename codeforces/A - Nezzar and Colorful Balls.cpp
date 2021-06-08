// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int a[N], n;
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
   scanf("%d", a+i); 
  int ans = 1;
  for (int i = 0; i < n; i++)
  {
   int j = i+1;
   while(j < n && a[j] == a[i])
    j++;
   ans = max(ans, j - i); 
   i = j-1;
  }
  printf("%d\n", ans); 
}
int main()
{
 int t = 1; 
 scanf("%d", &t); 
 while(t--)
  test(); 
}
