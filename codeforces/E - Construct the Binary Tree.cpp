// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 5e3 + 9;
int n, d;
int par[N], deg[N], dep[N];
void solve()
{
  cin >> n >> d;
  int cur = (n * (n-1))/2;
  if (d > cur)
  {
    cout <<"NO\n";
    return;
  }
  for (int i = 1; i < n; i++)
    par[i] = i-1, deg[i] = 1, dep[i] = i;
  deg[n-1] = 0;
  deg[0] = 1;
  while(cur > d)
  {
    int mxdep = -1;
    int node;
    for (int i = 0; i < n; i++)
    {
      if (dep[i] > mxdep && deg[i] == 0)
        mxdep = dep[i], node = i;
    }
    int best = -1;
    int node1;
    int need = cur - d;
    for (int i = 0; i < n; i++)
    {
      int getFromswap = dep[node] - dep[i]-1;
      if (dep[i] >= dep[node] || getFromswap > need || deg[i] == 2)continue;
      if (getFromswap > best)
        best = getFromswap, node1 = i;
    }
    if (best <= 0)break;
    deg[par[node]]--;
    dep[node] = dep[node1]+1;
    par[node] = node1;
    deg[node1]++;
    cur -= best;
  }
  if (cur != d)
  {
    cout <<"NO\n";
    return;
  }
  cout <<"YES\n";
  for (int i = 1; i < n; i++)
    cout << par[i]+1 <<" \n"[i==n-1];
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
}
