// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 1e5;
int n;
vector<int> adj[N];
int color[N];
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  queue<int> q;
  q.push(0);
  memset(color, -1, sizeof color);
  color[0] = 0;
  while(!q.empty())
  {
    int cur = q.front();
    q.pop();
    for (int i : adj[cur])
    {
      if (color[i] == -1)
      {
        color[i] = 1 - color[cur];
        q.push(i);
      }
    }
  }
  ll b = 0, ans = 0;
  for (int i = 0; i < n; i++) b += (color[i] == 1);
  for (int i = 0; i < n; i++)
  {
    if (color[i] == 1)continue;
    ll rm = b - SZ(adj[i]);
    ans += rm;
  }
  printf("%lld\n", ans);
 
 
}
