// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int a[3], n;
void test()
{
 scanf("%d", &n);
 a[0] = a[1] = a[2] = 0; 
 for (int i = 0; i < n; i++)
 {
  int x;scanf("%d", &x);
  a[x%3]++; 
 }
 int ans = 0;
 n/=3;
 for (int i = 0; i < 3; i++)
 {
  if (a[i] >= n)continue;
  int prv = (i-1+3)%3; 
  int nxt = (i+1)%3; 
  if (a[prv] > n)
  {
   int tk = a[prv] - n; 
   int need = n - a[i]; 
   int mn = min(need, tk); 
   ans += mn; 
   a[i] += mn; 
   a[prv] -= mn; 
   i--;
   continue; 
  }else 
  {
   int tk = a[nxt] - n; 
   int need = n - a[i];
   int mn = min(need, tk); 
   ans += 2 * mn; 
   a[i] += mn; 
   a[nxt] -= mn; 
   i--;
   continue; 
  }
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
