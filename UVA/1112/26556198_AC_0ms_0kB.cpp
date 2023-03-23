// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 101;
vector<pair<int,int>> adj[N];
int n, e, t, m, cost[N];
int dijkstra()
{
  memset(cost, -1, sizeof cost);
  cost[e] = 0;
  priority_queue<pair<int,int>> pq;
  pq.push({0, e});
  while(!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    for (auto i: adj[cur.s])
    {
      if (cost[i.f] == -1 || cost[i.f] > cost[cur.s] + i.s)
      {
        cost[i.f] = cost[cur.s] + i.s;
        pq.push({-cost[i.f], i.f});
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)if (cost[i] != -1 && cost[i] <= t)ans++;
  return ans;
}
int main()
{
  int ti;
  cin >> ti;
  while(ti--)
  {
    cin >> n >> e >> t >> m;
    for (int i = 1; i <= n; i++)adj[i].clear();
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      adj[v].pb({u, c});
    }
    cout << dijkstra() <<"\n";
    if (ti)cout <<"\n";
  }
}
