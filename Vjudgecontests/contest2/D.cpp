// Author : Mohamed Sameh
// created in: 9:11 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int n, m;
int g[18];
int dp[N], seen[N];
bool canBeAdded(int msk, int p){
  return (g[p] & msk) == msk;
}
string print(int num){
  string s = "";
  for (int i = n-1; i >= 0; i--){
    if (num & (1<<i))
      s += to_string(i+1) + " ";
  }
  return s;
}
void test(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    g[u] |= (1<<v);
    g[v] |= (1<<u);
  }
  for (int i = 0; i < (1<<n); i++)
  {
    dp[i] = 0;
    for (int j = 0; j < n; j++)
      dp[i] += (i & (1<<j)) != 0;
  }
  queue<int> q;
  q.push(0);
  while (!q.empty()){
    int msk = q.front();
    q.pop();
    vector<int> nn;
    for (int p = 0; p < n; p++){
      if (msk & (1<<p)) continue;
      if (canBeAdded(msk, p))
        dp[msk|(1<<p)] = min(dp[msk|(1<<p)], dp[msk] + dp[p]);
    }
    for (int p = 0; p < n; p++) {
      if (msk & (1 << p)) continue;
      int newMsk = msk | (1 << p);

      if (dp[newMsk] > 1 && !seen[newMsk]){
        for (int sub = (newMsk & (newMsk - 1)); sub != 0; sub = ((sub - 1) & newMsk)) {
          dp[newMsk] = min(dp[newMsk], dp[sub] + dp[newMsk ^ sub]);
        }
      }
      if (!seen[newMsk])
      {
        nn.push_back(newMsk);
        q.push(newMsk);
      }
      seen[newMsk] = 1;
    }
    for (int i: nn){
      printf("[%s %d]", print(i).c_str(), dp[i]);
    }
    if (nn.size() > 0)
      printf("\n");
  }
  printf("%d\n", dp[(1<<n) - 1]);
}
int main()
{
  test();
}