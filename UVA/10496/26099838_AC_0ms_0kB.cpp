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
const int N = 10;
int pos[N][2], dp[2*N][2*N][1<<N], px, py, sz;
int dist(int x1, int y1, int x2, int y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}
int solve(int x = px, int y = py, int msk = 0)
{
  if (msk == (1<<sz)-1)return dist(x, y, px, py);
  int &ret = dp[x][y][msk];
  if (~ret)return ret;
  ret = 1e9;
  for (int i = 0; i < sz; i++)
  {
    if ((msk&(1<<i)))continue;
    ret = min(ret, dist(x, y, pos[i][0], pos[i][1]) + solve(pos[i][0], pos[i][1], (msk | (1<<i))));
  }
  return ret;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d%d%d%d", &px, &px, &px, &py, &sz);
    px--;
    py--;
    for (int i = 0; i < sz; i++)
    {
      scanf("%d%d", pos[i], pos[i]+1);
      pos[i][0]--;
      pos[i][1]--;
    }
    memset(dp, -1, sizeof dp);
    printf("The shortest path has length %d\n", solve());
  }
}
