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
const int N = 600;
int n;
vector<pair<int,int>> adj[N];
string mp = "0123456789";
string getstr(int x)
{
  string str = "";
  while(x)
  {
    str += mp[x%10];
    x/=10;
  }
  while(SZ(str) != 4)str+='0';
  reverse(all(str));
  return str;
}
bool seen[N];
int Mst()
{
  memset(seen, 0, sizeof seen);
  priority_queue<pair<int,int>> pq;
  pq.push({0, 0});
  int ans = 0;
  while(!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    if (seen[cur.s])continue;
    ans += -cur.f;
    seen[cur.s] = 1;
    for (auto i: adj[cur.s])
      if (!seen[i.f])
        pq.push({-i.s, i.f});
  }
  return ans;
}
int cost(string a, string b)
{
  int c = 0;
  for (int k = 0; k < 4; k++)
  {
    int d1 = a[k]-'0';
    int d2 = b[k]-'0';
    c += min(abs(d1 - d2), 10 - abs(d1 - d2));
  }
  return c;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for (int i = 0; i < N; i++)adj[i].clear();
    vector<string> nodes;
    int mn = 1e9;
    for (int i = 0; i < n; i++)
    {
      string x;
      cin >> x;
      nodes.pb(x);
      mn = min(mn, cost(x, "0000"));
    }
    for (int i = 0; i < SZ(nodes); i++)
      for (int j = i+1; j < SZ(nodes); j++)
      {
        int c = cost(nodes[i], nodes[j]);
        adj[i].pb({j, c});
        adj[j].pb({i, c});
      }
      cout << Mst() + mn <<"\n";
  }
}