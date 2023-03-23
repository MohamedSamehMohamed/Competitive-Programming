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
const int N = 200;
int n, m;
vector<int> adj[N];
int color[N];
int main()
{
  while(scanf("%d", &n) && n)
  {
    for (int i = 0; i < n; i++)
    {
      adj[i].clear();
      color[i] = -1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].pb(v);
      adj[v].pb(u);
    }
    queue<int> q;
    q.push(0);
    color[0] = 0;
    bool ok = 1;
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
        }else if (color[i] == color[cur])
        {
          ok = 0;
          break;
        }
      }
    }
    printf("%s\n", (ok? "BICOLORABLE." : "NOT BICOLORABLE."));
  }
}
