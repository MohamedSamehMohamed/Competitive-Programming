// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n;
const int N = 4e2+9;
int a[N];
ll dp[N][N];
ll pre[N];
ll sum (int l, int r)
{
  return pre[r] - (l - 1 >= 0 ? pre[l-1] : 0);
}
void test ()
{
   cin >> n;
   for (int i = 0; i < n; i++)
    cin >> a[i];
   pre[0] = a[0];
   for (int i = 1; i < n; i++)pre[i] = pre[i-1] + a[i];
   for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = (i != j ? 1e18 : 0);
   for (int i = 0; i + 1 < n; i++) dp[i][i+1] = a[i]  + a[i+1];
   for (int k = 2; k < n; k++)
   {
     for (int i = 0; i + k < n; i++)
     {
       for (int j = i; j < i + k; j++)
       {
          ll cst = dp[i][j] + dp[j+1][i+k];
          dp[i][i+k] = min(dp[i][i+k] , cst + sum(i, i+k));
       }
    }
   }
   cout << dp[0][n-1] <<"\n";
}
int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  test();
}
