#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, M = 1e3 + 9; 
int a[N], frq[M], n, m, k;
bool can(int len)
{
 memset(frq, 0, sizeof frq);
 int seen = 0;
 for (int i = 0; i < len-1; i++)if (++frq[a[i]] == 1 && a[i] >= 1 && a[i] <= k)seen++;  
 for (int i = 0, j = len-1; j < n; i++, j++)
 {
  if (++frq[a[j]] == 1 && a[j] >= 1 && a[j] <= k)seen++;
  if (seen == k)return 1;
  if (--frq[a[i]] == 0 && a[i] >= 1 && a[i] <= k)seen--; 
 }
 return 0;
} 
int solve()
{
 scanf("%d%d%d", &n, &m, &k);
 for (int i = 0; i < 3; i++) a[i] = i + 1; 
 for (int i = 3; i < n; i++)
  a[i] = (a[i-1] + a[i-2] + a[i-3]) % m + 1; 
 int l = k, r = n, ans = -1; 
 while(l <= r)
 {
  int mid = (l+r) >> 1; 
  if (can(mid))
   ans = mid, r = mid - 1; 
  else 
   l = mid + 1; 
 }
 return ans;
}
int main()
{
 int t;
 scanf("%d", &t); 
 for (int i = 1; i <= t; i++)
 {
  printf("Case %d: ", i); 
  int ans = solve();
  if (ans < 0)
   printf("sequence nai\n"); 
  else 
   printf("%d\n", ans); 
 }
}
