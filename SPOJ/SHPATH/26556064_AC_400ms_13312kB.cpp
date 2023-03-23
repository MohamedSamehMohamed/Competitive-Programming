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
const int N = 1e4+9;
int cost[N], n;
vector<pair<int,int>> adj[N];
int dijkstra(int src, int tar)
{
  memset(cost, -1, 4 * n);
  cost[src] = 0;
  priority_queue<pair<int,int>> pq;
  for (auto i: adj[src])
    {
      cost[i.f] = i.s;
      pq.push({-cost[i.f], i.f});
    }
  while(!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    if (cost[cur.s] < -cur.f)continue;
    if (cur.s == tar) return cost[tar];
    for (auto i: adj[cur.s])
    {
      if (cost[i.f] == -1 || cost[i.f] > cost[cur.s] + i.s)
      {
        cost[i.f] = cost[cur.s] + i.s;
        pq.push({-cost[i.f], i.f});
      }
    }
  }
  return cost[tar];
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    map<string, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++)adj[i].clear();
    for (int i = 0; i < n; i++)
    {
      string str;
      cin >> str;
      mp[str] = i;
      int p, v, c;
      cin >> p;
      while(p--)
      {
        cin >> v >> c;
        v--;
        adj[i].pb({v, c});
        adj[v].pb({i, c});
      }
    }
    int q;
    cin >> q;
    while(q--)
    {
      string name1, name2;
      cin >> name1 >> name2;
      cout << dijkstra(mp[name1], mp[name2]) <<"\n";
    }
  }
}
