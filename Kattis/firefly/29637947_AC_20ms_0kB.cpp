// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
int n, h, lvl[N]; 
int main()
{
 scanf("%d%d", &n, &h);
 for (int i = 0, x; i < n; i++)
 {
  scanf("%d", &x);
  if (i%2==0)
   lvl[1]++, lvl[x+1]--; 
  else 
   lvl[h-x+1]++, lvl[h+1]--; 
 }
 int mn = 1e9;
 for (int i = 1; i <= h; i++)
  lvl[i] += lvl[i-1], mn = min(mn, lvl[i]);
 int cnt = count(lvl+1, lvl+1+h, mn); 
 printf("%d %d\n", mn, cnt);  
}