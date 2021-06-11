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
const int N = 201;
int R, G, B;
vector<int> rgb[3];
ll dp[N][N][N];
ll solve(int i = 0, int j = 0, int k = 0)
{
  ll &ret = dp[i][j][k];
  if (~ret)return ret;
  ret = 0;
  int ar[3] = {i, j, k};
  for (int tk1 = 0; tk1 < 3; tk1++)
    for (int tk2 = 0; tk2 < 3; tk2++)
    {
      if (tk1 == tk2)continue;
      if (ar[tk1] == SZ(rgb[tk1]))continue;
      if (ar[tk2] == SZ(rgb[tk2]))continue;
      ll cur = 1LL*rgb[tk1][ar[tk1]] * rgb[tk2][ar[tk2]];
      ar[tk1]++;
      ar[tk2]++;
      ret = max(ret, cur + solve(ar[0], ar[1], ar[2]));
      ar[tk1]--;
      ar[tk2]--;
    }
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  cin >> R >> G >> B;
  rgb[0] = vector<int>(R);
  rgb[1] = vector<int>(G);
  rgb[2] = vector<int>(B);
  for (int i = 0; i < R; i++)cin >> rgb[0][i];
  for (int i = 0; i < G; i++)cin >> rgb[1][i];
  for (int i = 0; i < B; i++)cin >> rgb[2][i];
  for (int i = 0; i < 3; i++)sort(rall(rgb[i]));
  cout << solve() << "\n";
}
