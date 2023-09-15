#include<bits/stdc++.h>
 
using namespace std;
const int N = 1e6 + 9;  
int vis[N], cnt;
void factorize(int x)
{
 for (int i = 2; x != 1 && i <= x/i; i++)
 {
  if (x % i == 0)
  {
   vis[i]++; 
  }
  while(x % i == 0)
  {
   x/=i; 
  }
 }
 if (x != 1)
  vis[x]++; 
}
void solve()
{
 memset(vis, 0, sizeof vis); 
 cnt = 0; 
 int n; 
 scanf("%d", &n); 
 for (int i = 0; i < n; i++)
 {
  int x; 
  scanf("%d", &x); 
  factorize(x); 
 }
 for (int i = 2; i < N; i++)
 {
  cnt += (vis[i] + 2) / 3; 
 }
 printf("%d\n", cnt); 
}
int main()
{
 int t; 
 scanf("%d", &t); 
 while(t--)
 {
  solve(); 
 }
 
}
