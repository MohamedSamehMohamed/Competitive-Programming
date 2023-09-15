// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 501;
int n;
int mat[N][N];
int a[N];
ll dp[N][N];
bool seen[N];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", mat[i] + j);
  for (int i = 0; i < n; i++)scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      dp[i][j] = mat[i][j];
    }
  ll sum = 0;
  stack<ll> sk;
  for (int k = n-1; k >= 0; k--)
  {
    int node = a[k]-1;
    seen[node] = 1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        dp[i][j] = min(dp[i][j], dp[i][node] + dp[node][j]);
      }
    }
    sum = 0;
    for (int i = k; i < n; i++)
      for (int j = k; j < n; j++)
          sum += dp[a[i]-1][a[j]-1];
    sk.push(sum);
  }
  while(!sk.empty())
  {
    printf("%lld ", sk.top());
    sk.pop();
  }
  printf("\n");

}
