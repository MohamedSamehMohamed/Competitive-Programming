// Author : Mohamed Sameh
// created in: 1:30 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int a[N][N], n, m;
int dp[N][N][2];
void test(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
  for (int i = n-1; i >= 0; i--){
    for (int j = m-1; j >= 0; j--){
      for (int k = 0; k < 2; k++) {
        int val = (k == 0? 1: -1);
        dp[i][j][k] = (a[i][j] == val);
        int right = (j + 1 < m ? dp[i][j + 1][k] : 0);
        int down = (i + 1 < n ? dp[i + 1][j][k] : 0);
        dp[i][j][k] = max(dp[i][j][k], right + (a[i][j] == val));
        dp[i][j][k] = max(dp[i][j][k], down + (a[i][j] == val));
      }
    }
  }
  if ((n+m) % 2 == 0)
  {
    printf("No\n");
    return;
  }
  /*
  int r = 0, c = 0;
  int need[2] = {(m+n)/2, (m+n)/2};
  while (r < n && c < m){
    int cur = a[r][c] == 1? 0: 1;
    if (r == n-1 && c == m - 1){
      need[cur]--;
      break;
    }
    if (r + 1 < n){
      need[cur]--;
      if (dp[r+1][c][0] >= need[0] && dp[r+1][c][1] >= need[1]){
        r++;
        continue;
      }
      need[cur]++;
    }
    if (c + 1 < m){
      need[cur]--;
      if (dp[r][c+1][0] >= need[0] && dp[r][c+1][1] >= need[1]){
        c++;
        continue;
      }
      need[cur]++;
    }
    printf("No\n");
    return;
  }
  */
  if (dp[0][0][0] >= (n+m)/2 && dp[0][0][1] >= (n+m)/2)
    printf("Yes\n");
  else
    printf("No\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}