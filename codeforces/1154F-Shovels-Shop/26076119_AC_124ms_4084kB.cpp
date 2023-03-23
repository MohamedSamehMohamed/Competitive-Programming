// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 2e3+9;
int n, m, k;
priority_queue<int> tq;
int a[N], dp[N], tarr[N];
int pre[N];
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
  {
    int v;
    scanf("%d", &v);
    tq.push(v);
    while (tq.size() > k)tq.pop();
  }
  for (int i = 0; i < k; i++)
  {
    a[i] = tq.top();
    tq.pop();
  }
  for (int i = 0; i < k; i++)pre[i+1]=pre[i] + a[i];
  for (int i = 0; i < m; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > k)continue;
    tarr[x] = max(tarr[x], y);
  }
  n = k ;
  for (int i = 0; i <= n; i++) dp[i] = 2e9;
  dp[0] = 0;
  for (int i = 0; i < n; i++)
  {
    dp[i+1] = min(dp[i+1], dp[i] + a[i]);
    for (int j = 1;i + j <= n; j++)
    {
      if (tarr[j] == 0)continue;
      dp[i + j] = min(dp[i+j], dp[i] + pre[i+j-tarr[j]] - pre[i]);
    }
  }
  printf("%d\n", dp[n]);
}
