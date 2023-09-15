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
const int N = 31;
const int M = 51;
int n, m, k;
int dp[N][N][M];
int solve(int w = n, int h = m, int rem = k)
{
  int s = w * h;
  //cout << s <<" " << rem <<"\n";
  if (s == rem || rem == 0)return 0;
  if (s < rem)return 1e9;
  int &ret = dp[w][h][rem];
  if (~ret)return ret;
  ret = 1e9;
  for (int i = 1; i < w; i++)
  {
    for (int j = 0; j <= rem; j++)
    {
      int sp  = rem - j;
      int cst = h*h;
      ret = min(ret, cst + solve(i, h, j) + solve(w - i, h, sp));
    }
  }
  for (int i = 1; i < h; i++)
  {
    for (int j = 0; j <= rem; j++)
    {
      int sp  = rem - j;
      int cst = w*w;
      ret = min(ret, cst + solve(w, i, j) + solve(w, h-i, sp));
    }
  }
  return ret;
 
}
void test ()
{
  scanf("%d%d%d", &n, &m, &k);
  printf ("%d\n", solve());
}
int main()
{
  memset(dp, -1, sizeof dp);
  int t;
  scanf("%d", &t);
  while(t--)test();
}
