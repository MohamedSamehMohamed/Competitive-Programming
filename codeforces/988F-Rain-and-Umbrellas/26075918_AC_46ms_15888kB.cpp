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
const int N = 2e3+9, Mx = 1e9;
int wet[N];
int umps[N];
int dp[N][N+1];
int mx, n, m;
int solve(int i = 0, int idx = N)
{
  if (i == mx)return 0;
  int &ret = dp[i][idx];
  if (~ret)return ret;
  ret = 1e9;
  if (!wet[i]) ret = solve(i+1, N);
  if (umps[i] != -1)ret = min(ret, umps[i] + solve(i+1, i));
  if (idx != N)ret = min(ret, umps[idx] + solve(i+1, idx));
  return ret;
}
void build(int i = 0, int idx = N)
{
  if (i == mx)return ;
  int ret = dp[i][idx];
  if (!wet[i]){
  int p1  = solve(i+1, N);
  if (p1 == ret)
  {
    cout <<"0";
    build(i+1, N);
    return;
  }
  }

  if (umps[i] != -1){
    int p1 = umps[i] + solve(i+1, i);
    if (ret == p1)
    {
      cout <<"{" << umps[i]<<"}";
      build(i+1, i);
      return;
    }
  }
  if (idx != N){
    int p1 = umps[idx] + solve(i+1, idx);
    if (p1 == ret)
    {
      cout << "{" << umps[idx]<<"}";
      build(i+1, idx);
    }
  }
}
int main()
{
  memset(dp, -1, sizeof dp);
  memset(umps, -1, sizeof umps);
  scanf("%d%d%d", &mx, &n, &m);
  for (int i = 0; i < n; i++)
  {
    int l, r ;
    scanf("%d%d", &l, &r);
    wet[l]++;
    wet[r]--;
  }
  for (int i = 1; i < N; i++)
    wet[i] += wet[i-1];

  for (int i = 0; i < m; i++)
  {
    int p, w;
    scanf("%d%d", &p, &w);
    if (umps[p] == -1)umps[p] = w;
    umps[p] = min(umps[p], w);
  }
  int ans = solve();
  if (ans == 1e9)ans =-1;
  printf ("%d\n", ans);
//  build();
}
