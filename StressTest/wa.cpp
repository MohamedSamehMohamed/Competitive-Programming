// Author : Mohamed Sameh
// created in: 7:12 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+2, M = 1 << 13;
int a[N], n, mex[N][N], dp[N][M];
int dp_vis[N][M], dp_vis_id;
int seen[N], seenId;
int solve(int i = 0, int msk = 0){
  if (i == n)
    return msk;
  int& ret = dp[i][msk];
  if (dp_vis[i][msk] == dp_vis_id)
    return ret;
  dp_vis[i][msk] = dp_vis_id;
  ret = solve(i+1, msk);
  for (int j = i; j < n; j++)
    ret = max(ret, solve(j+1, msk ^ mex[i][j]));
  return ret;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++){
    seenId++;
    int curMx = 0;
    for (int j = i; j < n; j++){
      seen[a[j]] = seenId;
      while (seen[curMx] == seenId)
        curMx++;
      mex[i][j] = curMx;
    }
  }
  dp_vis_id++;
  printf("%d\n", solve());
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}