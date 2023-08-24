#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int pre[N], changes[N], seg[N][2], n, m, q;
bool can(int numOfChanges){
  memset(pre, 0, sizeof(pre[0]) * (n + 1));
  for (int i = 0; i < numOfChanges; i++){
    pre[changes[i]] = 1;
  }
  for (int i = 1; i <= n; i++)
    pre[i] += pre[i-1];
  for (int i = 0; i < m; i++){
    int len = seg[i][1] - seg[i][0] + 1;
    int numOfOnes = pre[seg[i][1]] - pre[seg[i][0] - 1];
    if (2 * numOfOnes > len)
      return 1;
  }
  return 0;
}
void solve(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++){
    scanf("%d%d", seg[i], seg[i] + 1);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++){
    scanf("%d", changes + i);
  }
  int l = 1, r = q, ans = -1;
  while (l <= r){
    int mid = (l+r) >> 1;
    if (can(mid)){
      ans = mid;
      r = mid - 1;
    }else 
      l = mid + 1;
  }
  printf("%d\n", ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}


