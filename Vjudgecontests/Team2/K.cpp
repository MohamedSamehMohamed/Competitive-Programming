// Author : Mohamed Sameh
// created in: 12:03 AM
#include <bits/stdc++.h>
using namespace std;
// testing the correctness [2^10] -> 1024
const int N = 3e5 + 9, LOG = 12, mod = 998244353;
int valueInKthDay[N][LOG][LOG];
int kthParent[N][LOG];
int n, fun[N], nodeValue[N];
vector<int> adj[N];
int dep[N];
void dfsCalc(int u = 0, int p = -1){
  dep[u] = 0;
  for (int v: adj[u]){
    if (v == p) continue;
    dfsCalc(v, u);
    dep[u] = max(dep[u], dep[v] + 1);
  }
}
void dfs(int u = 0, int p = -1, int walk = 0){
  if (p == -1){
    for (int i = 0; i < LOG; i++){
      kthParent[u][i] = -1;
      if ((1<<i) <= n)
        valueInKthDay[u][(1<<i)][0] =
                (1LL * nodeValue[u] * fun[(1<<i)-1])%mod;
    }
  }else {
    kthParent[u][0] = p;
    for (int i = 0; i + 1 < LOG; i++){
      int par = kthParent[u][i];
      if (par == -1)
        kthParent[u][i+1] = -1;
      else {
        kthParent[u][i+1] = kthParent[par][i];
      }
    }
  }
  for (int i = 0; (1<<i) <= dep[u]+1; i++){
    int d = (1<<i) - 1;
    valueInKthDay[u][i][0] = (1LL * nodeValue[u] * fun[d]) % mod;
    for (int cnt = 1; cnt < LOG; cnt++){
      int parent = kthParent[u][cnt-1];
      if (parent == -1)break;
      int nextDay = (1<<i) + (1<<(cnt-1));
      int lg = 0;
      int plg = 1;
      while (plg < nextDay){
        plg *= 2;
        lg++;
      }

      if (plg == nextDay){
        valueInKthDay[u][i][cnt] = (1LL * valueInKthDay[u][i][cnt-1] +
                                    valueInKthDay[parent][lg][cnt-1])%mod;
      }
    }
  }
  for (int v: adj[u]){
    if (v == p) continue;
    dfs(v, u, walk+1);
  }
  dep[u] = walk + 1;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    adj[i].clear();
  for (int i = 0; i < LOG; i++)
    kthParent[0][i] = -1;
  for (int i = 0; i < n; i++){
    scanf("%d", fun + i);
  }
  for (int i = 0; i < n; i++){
    scanf("%d", nodeValue + i);
  }
  for (int i = 0; i < n - 1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(valueInKthDay, -1, sizeof valueInKthDay);
  dfsCalc();
  dfs();
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    int node = i, d = 0;
    int day = 1;
    while (true) {
      for (int j = LOG - 1; j >= 0; j--) {
        if (valueInKthDay[node][d][j] != -1) {
          sum = (sum + valueInKthDay[node][d][j]) % mod;
          day += (1 << j);
          node = kthParent[node][j];
          while ((1 << d) < day)
            d++;
          if ((1 << d) > day) break;
        }
      }
      if (day > dep[i]) break;
      while ((1<<d) > day){
        if (day-1 >= 0)
          sum += (1LL * fun[day-1] * nodeValue[node]);
        sum %= mod;
        day++;
        node = kthParent[node][0];
      }
      if (day > dep[i]) break;
    }
    printf("%d\n", sum);
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}