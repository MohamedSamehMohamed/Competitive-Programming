// Author : Mohamed Sameh
// created in: 8:57 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9, mod = 1e9 + 7;
vector<int> adj[N];
int subSum[N];
int n;
void dfs(int u = 0, int p = -1){
  subSum[u] = 1;
  for (int v: adj[u]){
    if (v == p) continue;
    dfs(v, u);
    subSum[u] += subSum[v];
  }
}
int ans;
int fast(int b, int p)
{
  if (p == 0)return 1;
  if (p&1)return (1LL * b * fast(b, p - 1)%mod)%mod;
  int cur = fast(b, p/2) % mod;
  return (1LL * cur * cur) % mod;
}
long long sum(int num){
  num %= mod;
  long long cur = (1LL * num * (num-1))%mod;
  cur %= mod;
  if (cur < 0) cur += mod;
  cur = (cur * fast(2, mod - 2))%mod;
  cur %= mod;
  if (cur < 0) cur += mod;
  return cur;
}

void count(int u = 0, int p = -1){
  long long total = 0;
  int totCh = 0;
  for (int v: adj[u]){
    if (v != p)
      totCh += subSum[v];
  }
  for (int v: adj[u]){
    int down = subSum[v];
    int up = n - down - 1;
    if (v == p){
      down = totCh;
      up = n - down - 1;
    }
    total = (total + (1LL * down * up) % mod) % mod;
  }
  total = (total * fast(2, mod - 2)) % mod;
  total += n-1;
  total %= mod;
  // 2e5 * 2e5 * 2e5 * 2e5 A7a
  ans = (1LL * ans + sum(total)%mod) % mod;
  for (int v: adj[u]){
    if (v == p) continue;
    count(v, u);
  }
}

void test(){
  scanf("%d", &n);
  for (int i = 0; i <n ;i++)
  {
    subSum[i] = 0;
    adj[i].clear();
  }
  for (int i = 1; i < n; i++){
    int v;scanf("%d", &v);
    adj[i].push_back(v-1);
    adj[v-1].push_back(i);
  }
  ans = 0;
  dfs();
  count();
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}