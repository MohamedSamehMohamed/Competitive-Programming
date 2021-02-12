// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int h[N], cost[N], n;
long long HC[N], a[N]; 
void test()
{
 memset(HC, 0, sizeof HC);
 memset(a, 0, sizeof a); 
 scanf("%d", &n);
 for (int i = 0; i < n; i++)scanf("%d", h+i); 
 for (int i = 0; i < n; i++)scanf("%d", cost+i);
 int mx = *max_element(h, h+n); 
 for (int i = 0; i < n; i++)
 {
  HC[h[i] + 1] += cost[i];
  a[h[i]+2] += cost[i];
  if (h[i] == 0)continue;  
  HC[0] += 1LL * h[i] * cost[i]; 
  HC[h[i]] -= cost[i]; 
  a[1] -= cost[i];
  a[h[i]] += cost[i]; 
 }
 long long pre = a[0]; 
 for (int i = 1; i < N; i++)
 {
  pre += a[i]; 
  HC[i] += HC[i-1] + pre; 
 }
 long long ans = HC[0];
 for (int i = 0; i <= mx; i++)ans = min(ans, HC[i]); 
 printf("%lld\n", ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
