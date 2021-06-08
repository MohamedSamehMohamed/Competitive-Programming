// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, a[N], ans;
vector<int> adj[N];
int out[N];
void solve(int u = 0, int par = -1, int flips = 0, int extra = 0)
{
  int tem = extra;
  if (flips % 2)
  {
    if (!a[u])
      extra++, out[ans++] = u+1;
  }else
  {
    if (a[u])
      extra++, out[ans++] = u+1;
  }
  flips += tem;
  for (int v: adj[u])
    if (v != par)
      solve(v, u, flips, extra);
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0, x; i < n; i++)
  {
    scanf("%d", &x);
    a[i] ^= x;
  }
  solve();
  printf("%d\n", ans);
  for (int i = 0; i < ans; i++)
    printf("%d\n", out[i]);
}
