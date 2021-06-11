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
const int N = 1009;
int a[N], ans[N], n;
int find_min(int l, int r)
{
  int idx = l;
  while(l <= r)
  {
    if (a[l] < a[idx])idx = l;
    l++;
  }
  return idx;
}
void Fill(int l, int r, int val)
{
  while(l <= r)
  {
    ans[l] = val;
    l++;
  }
}
ll dp[N][N];
ll solve(int l = 0, int r = n-1)
{
  if (l > r)return 0;
  ll &ret = dp[l][r];
  if (~ret)return ret;
  int idx = find_min(l, r);
  int left  = idx - l + 1;
  int right = r - idx + 1;
  ret = 1LL * left * a[idx] + solve(idx+1, r);
  ret = max(ret, 1LL * right * a[idx] + solve(l, idx-1));
  return ret;
}
void build(int l = 0, int r = n-1)
{
  if (l > r)return ;
  ll ret = dp[l][r];
  int idx = find_min(l, r);
  int left  = idx - l + 1;
  int right = r - idx + 1;
  ll p1 = 1LL * left * a[idx] + solve(idx+1, r);
  ll p2 = 1LL * right * a[idx] + solve(l, idx-1);
  if (ret == p1)
  {
    Fill(l, idx, a[idx]);
    build(idx+1, r);
  }else
  {
    Fill(idx, r, a[idx]);
    build(l, idx-1);
  }
}
int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  solve();
  build();
  for (int i = 0; i < n; i++)
    cout << ans[i] <<" ";
  cout <<"\n";
}
