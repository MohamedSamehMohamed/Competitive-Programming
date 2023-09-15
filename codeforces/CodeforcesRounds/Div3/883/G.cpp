#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int n, m;
char s[20];
int cure[N][3];
int getMsk(){
  int msk = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '1')
      msk |= (1<<i);
  }
  return msk;
}
int dp[1<<10];
void test(){
  scanf("%d%d", &n, &m);
  scanf(" %s", s);
  int myBad = getMsk();
  for (int i = 0; i < m; i++){
    scanf("%d", cure[i]);
    for (int j = 0; j < 2; j++){
      scanf(" %s", s);
      cure[i][1 + j] = getMsk();
    }
  }
  memset(dp, -1, sizeof dp);
  priority_queue<vector<int>> pq;
  pq.push({0, myBad});
  dp[myBad] = 0;
  while (!pq.empty()){
    int cur = pq.top()[1];
    pq.pop();
    for (int i = 0; i < m; i++){
      int newMsk = cur;
      newMsk &= ~cure[i][1];
      newMsk |= cure[i][2];
      if (dp[newMsk] == -1 || dp[newMsk] > dp[cur] + cure[i][0]){
        dp[newMsk] = cure[i][0] + dp[cur];
        pq.push({-dp[newMsk], newMsk});
      }
    }
  }
  printf("%d\n", dp[0]);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}