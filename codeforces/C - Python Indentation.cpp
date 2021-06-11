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
const int N = 1e9+7, M = 5009;
int n;
char a[M];
int dp[M][M];
int solve(int i = 0, int ind = 0)
{
  if (i == n)return !ind;
  int &ret = dp[i][ind];
  if (~ret)return ret;
  ret = 0;
  if (a[i] == 's')
  {
    ret = solve(i+1, ind)%N;
    if (ind > 0)ret = (ret + solve(i, ind - 1)%N)%N;
  }else
  ret = solve(i+1, ind + 1);
  return ret;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)cin >> a[i];
  memset(dp, -1, sizeof dp);
  cout << solve() % N << '\n';
}
