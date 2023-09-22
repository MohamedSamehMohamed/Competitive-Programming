// Author : Mohamed Sameh
// created in: 7:12 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+2, M = 1 << 13;
int a[N], n, dp[N][M];
int seen[N], seenId;
vector<vector<int>> adj[N];
int mexPerRow[N];
int solve(int i = 0, int msk = 0){
  if (i == n)
    return msk;
  int& ret = dp[i][msk];
  if (~ret)
    return ret;
  ret = solve(i+1, msk);
  for (auto& j: adj[i])
    ret = max(ret, solve(j[0]+1, msk ^ j[1]));
  return ret;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int p = 0;
  while ((1<<p) < n)
    p++;
  for (int i = 0; i < n; i++)
  {
    mexPerRow[i] = -1;
    for (int j = 0; j < min(N, (1<<p) + 1); j++)
      dp[i][j] = -1;
  }

  for (int i = n-1; i > -1; i--){
    seenId++;
    int curMx = 0;
    int prv = -1;
    for (int j = i; j < n; j++){
      seen[a[j]] = seenId;
      while (seen[curMx] == seenId)
        curMx++;
      // mex increases only
      // if next can make same as I'm skip me
      if (curMx > prv && mexPerRow[j] != curMx)
        adj[i].push_back({j, curMx});
      else if (adj[i].size() == 0)
        adj[i].push_back({j, curMx});
      prv = curMx;
      mexPerRow[j] = curMx;
    }
  }
  /*
  for (int i = 0; i < n; i++){
    for (auto j: adj[i]){
      cout << "[" << j[0] <<", " << j[1] << "]";
    }
    cout <<"\n";
  }
   */
  printf("%d\n", solve());
  for (int i = 0; i < n; i++)
    adj[i].clear();
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}