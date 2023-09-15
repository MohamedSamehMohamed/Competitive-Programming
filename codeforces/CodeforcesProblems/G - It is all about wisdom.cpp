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
const int N = 1e5+ 20;
vector<array<int, 3>> adj[N];
ll cost[N];
int n, m, k;
bool dijkstra(int mx)
{
  memset(cost, -1, sizeof(cost[0]) * (n+1));
  cost[1] = 0;
  priority_queue<pair<ll,int>> pq;
  pq.push({0LL, 1});
  while(!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    if (cur.s == n)break;
    for (auto i: adj[cur.s])
    {
      if (i[2] > mx)continue;
      if (cost[i[0]] == -1 || cost[i[0]] > cost[cur.s] + i[1])
      {
        cost[i[0]] = cost[cur.s] + i[1];
        pq.push({-cost[i[0]], i[0]});
      }
    }
  }
  return cost[n] != -1 && cost[n] <= k;
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> m >> k;k--;
    for (int i = 1; i <= n; i++)adj[i].clear();
    for (int i = 0; i < m; i++)
    {
      int u, v, c, wis;
      cin >> u >> v >> c >> wis;
      adj[u].pb({v, c, wis});
      adj[v].pb({u, c, wis});
    }
    int l = 0, r = 1e9, ans = -1;
    while(l <= r)
    {
      int mid = (l+r)>>1;
      if (dijkstra(mid))
      {
        ans = mid;
        r = mid-1;
      }else
      l = mid+1;
    }
    cout << ans <<"\n";
  }
}
