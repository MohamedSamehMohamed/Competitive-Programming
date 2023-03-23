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
const int N = 14;
int n, m;
int value[N][2];
int st[2], en[2];
int dp[1<<N][N+1][N];
bool solve(int msk = 0, int lst = st[1], int rm = n)
{
  if (!rm) return lst == en[0];
  int &ret = dp[msk][lst][rm];
  if (~ret)return ret;
  ret = 0;
  for (int i = 0; i < m; i++)
  {
    if ((msk&(1<<i)))continue;
    if (value[i][0] == lst)ret = max(ret, (int)solve((msk | (1<<i)), value[i][1], rm-1));
    if (value[i][1] == lst)ret = max(ret, (int)solve((msk | (1<<i)), value[i][0], rm-1));
  }
  return ret;
}
int main()
{
  while (scanf("%d", &n) && n && scanf("%d", &m))
  {
    scanf("%d%d%d%d", st, st+1, en, en+1);
    for(int i = 0; i < m; i++)
    scanf("%d%d", value[i], value[i]+1);
    memset(dp, -1, sizeof dp);
    printf("%s\n", (solve()? "YES" : "NO"));
  }
}
