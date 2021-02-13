// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int h[N], cost[N], n;
long long pre[N+5], tem[N+5]; 
void addRange(int l, int r, long long st, int add)
{
 pre[l] += st;
 pre[r+1] -= st + 1LL*(r-l)*add;
 tem[l+1] += add;
 tem[r+1] -= add;  
}
void test()
{
 memset(pre, 0, sizeof pre);
 memset(tem, 0, sizeof tem); 
 scanf("%d", &n);
 for (int i = 0; i < n; i++)scanf("%d", h+i); 
 for (int i = 0; i < n; i++)scanf("%d", cost+i);
 for (int i = 0; i < n; i++)
 {
  addRange(h[i]+1, N, 1LL*cost[i], cost[i]); 
  if (h[i])
   addRange(0, h[i]-1, 1LL*cost[i] * h[i], -cost[i]);
 }
 long long add = tem[0]; 
 for (int i = 1; i < N; i++)
 {
  add += tem[i]; 
  pre[i] += pre[i-1] + add; 
 }
 long long ans = pre[0];
 for (int i = 0; i < N; i++)
  ans = min(ans, pre[i]); 
 printf("%lld\n", ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
