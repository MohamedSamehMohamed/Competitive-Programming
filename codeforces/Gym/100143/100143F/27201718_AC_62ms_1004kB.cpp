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
const int N = 60;
int h, w, n;
string x[60], str;
int dp[N][N][N];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int solve(int idx, int stx, int sty)
{
  if (idx == SZ(str))return 0;
  int &ret = dp[idx][stx][sty];
  if (~ret)return ret;
  ret = 0;
  for (int i = 0; i < 8; i++)
  {
    int nx = stx + dx[i];
    int ny = sty + dy[i];
    if (min(nx, ny) < 0 || nx == h || ny == w)continue;
    ret = max(ret, (x[nx][ny] == str[idx]) + solve(idx + 1, nx, ny));
  }
  return ret;
}
void build(int idx, int stx, int sty)
{
  cout << stx+1 <<" " << sty + 1 <<"\n";
  if (idx == SZ(str))return;
  int ret = dp[idx][stx][sty];
  for (int i = 0; i < 8; i++)
  {
    int nx = stx + dx[i];
    int ny = sty + dy[i];
    if (min(nx, ny) < 0 || nx == h || ny == w)continue;
    int way = (x[nx][ny] == str[idx]) + solve(idx + 1, nx, ny);
    if (way == ret)
    {
      build(idx+1, nx, ny);
      break;
    }
  }
}
int main()
{
  freopen("kingwalk.in", "r", stdin);
  freopen("kingwalk.out", "w", stdout);
  memset(dp, -1, sizeof dp);
  cin >> h >> w;
  for (int i = 0; i < h; i++)cin >> x[i];
  cin >> n;
  cin >> str;
  int ans = -1;
  int stx, sty;
  stx = 0;sty = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      {
        int cur = (str[0] == x[i][j]) + solve(1, i, j);
        if (cur > ans)
        {
          ans = cur;
          stx = i;
          sty = j;
        }
      }
  cout << ans << "\n";
  build(1, stx, sty);
}
