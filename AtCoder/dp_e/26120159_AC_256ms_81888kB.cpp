// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int M = 100 ;
const int MAXV = 1e5+1;
const ll MAX = 2e18+9;
ll dp[M][MAXV];
int w[M],v[M];
int N , W ;
ll solve(int i , int rm)
{
  if (!rm)return 0;
  if (rm < 0 || i == N) return MAX;
  ll &ret = dp[i][rm];
  if (~ret)return ret;
  ret = solve(i+1, rm);
  ret = min(ret, w[i] + solve(i+1, rm - v[i]));
  return ret;
}
int main ()
{
    scanf ("%d%d" , &N ,&W);
    for (int i =0 ; i < N ;i++)
    {
        scanf ("%d%d" ,w+i , v+i);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (int i= 0 ; i < MAXV ;i++)
    {
      if (solve(0, i) <= W)
        ans = i;
    }
    printf ("%d\n" , ans);
}
