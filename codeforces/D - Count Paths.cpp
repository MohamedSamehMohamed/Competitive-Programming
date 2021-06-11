// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std ;
const int N = 102;
int n, m, b, K;
vector<array<int, 3>> a(N); 
const ll Mx = 4e18;
ll dp[1<<20];
int main()
{
 for (int i = 0; i < (1<<20); i++)dp[i] = Mx;
 scanf("%d%d%d", &n, &m, &b);
 int tar = (1<<m) - 1; 
 for (int i = 0; i < n; i++)
 {
  scanf("%d%d", &a[i][0], &a[i][1]);
  int x, y;
  scanf("%d", &x);
  while(x--)
  {
   scanf("%d", &y); 
   y--;
   a[i][2]|=(1<<y); 
  }
 }
 
 a.resize(n); 
 sort(all(a), [](array<int, 3> &A, array<int, 3> &B){return A[1] < B[1];});
 ll ans = Mx;
 dp[0] = 0;
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j <= tar; j++)
  {
   if (dp[j] == Mx)continue;
   int msk = j | a[i][2];
   dp[msk] = min(dp[msk], dp[j] + a[i][0]); 
  }
  if (dp[tar] != Mx)ans = min(ans, dp[tar] + 1LL*a[i][1] * b); 
 }
 if (ans == Mx)ans = -1;
 printf("%lld", ans);
}
