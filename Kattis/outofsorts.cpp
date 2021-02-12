// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int ar[N], n, m, a, c, ans; 
void gen()
{
 for (int i = 1; i <= n; i++)
  ar[i] = (1LL*a * ar[i-1] + c) % m; 
}
void solve()
{
 for (int i = 1; i <= n; i++)
 {
  int l = 1, r = n; 
  while(l <= r)
  {
   int mid = (l+r)>>1; 
   if (ar[mid] == ar[i])
   {
    ans++;break; 
   } 
   if (ar[mid] < ar[i])
    l = mid + 1; 
   else 
    r = mid - 1; 
  }
 }
}
int main()
{
 scanf("%d%d%d%d%d", &n, &m, &a, &c, ar);
 gen(); 
 solve(); 
 printf("%d\n", ans); 
}
