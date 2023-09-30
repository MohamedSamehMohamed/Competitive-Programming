// Author : Mohamed Sameh
// created in: 12:40 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, mod = 998244353;
int n, s;
vector<int> adj[N];
int p2[N];
long long powMod(long long b, long long p){
  if (p == 0) return 1;
  if (p&1) return (b * powMod(b, p-1))%mod;
  long long ret = powMod(b, p / 2);
  return (ret * ret) % mod;
}
void test(){
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++)
    adj[i].clear();
  int mxW = 0;
  for (int i = 0; i < n - 1; i++){
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    mxW = max(mxW, w);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long ans = 1;
  for (int i = 0; i < n; i++){
    int rem = n - (int)adj[i].size() - 1;
    cout << rem <<" ";
    ans = (ans * p2[rem] * powMod(s - mxW, rem));
  }
  cout <<"\n";
  printf("%lld\n", ans);
}
int main()
{
  p2[0] = 1;
  for (int i = 1; i < N; i++)
    p2[i] = (1LL * p2[i-1] * 2) % mod;
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}