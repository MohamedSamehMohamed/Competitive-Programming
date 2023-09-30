// Author : Mohamed Sameh
// created in: 9:22 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
vector<int> adj[N];
long long dp[N][2];
long long solve(int index = 1, int lst = 0){
  if (index == n+1 || adj[index].size() == 0)
    return lst == 0? abs(adj[index-1][0]): abs(adj[index-1].back());
  long long& ret = dp[index][lst];
  if (~ret) return ret;
  int id = (lst == 0? 0: adj[index-1].size()-1);
  long long currentX = adj[index-1][id];
  int l = adj[index][0];
  int r = adj[index].back();
  if (currentX <= l){
    ret = solve(index+1, 1) + r - currentX;
  }else if (currentX >= r){
    ret = solve(index+1, 0) + currentX - l;
  }else {
    // in the middle
    ret = solve(index + 1, 0) + abs(currentX - r) + abs(r-l);
    ret = min(ret, solve(index+1, 1) + abs(currentX-l) + abs(r-l));
  }
  return ret;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    int x, c;
    scanf("%d%d", &x, &c);
    adj[c].push_back(x);
  }
  adj[0].push_back(0);
  for (int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());
  int j = 1;
  for (int i = 1; i <= n; i++){
    if (adj[i].size() > 0) continue;
    j = max(i+1, j);
    while (j <= n && adj[j].size() == 0)
      j++;
    if (j > n) break;
    swap(adj[i], adj[j]);
    j++;
  }
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve());
}
int main()
{
  test();
}