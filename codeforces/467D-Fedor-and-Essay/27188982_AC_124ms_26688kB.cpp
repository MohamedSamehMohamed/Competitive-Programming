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
const int N = 5e5+9;
vector<int> adj[N];
int n, m;
ll dp[N][2];
ll arr[N][2];
void con(string &x)
{
  for (int i = 0; i < SZ(x); i++)
  {
    if (x[i] < 'a')x[i] += 32;
  }
}
int cost(string x)
{
  int cnt = 0;
  for (int i = 0; i < SZ(x); i++)
  {
    cnt += (x[i] == 'r');
    if (x[i] < 'a')while(1);
  }
  return cnt;
}
int main()
{
  FAST
  for (int i = 0; i < N; i++)dp[i][0] = dp[i][1] = 1e17;
  cin >> n;
  vector<string> words(n);
  map<string, int> mp;
  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
    con(words[i]);
    if (mp.find(words[i]) == mp.end())
    {
      arr[idx][0]  = cost(words[i]);
      arr[idx][1]  = SZ(words[i]);
      mp[words[i]] = idx;idx++;
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    string x, y;
    cin >> x >> y;
    int u, v;
    con(x);
    con(y);
    if (mp.find(x) == mp.end())
    {
      arr[idx][0]  = cost(x);
      arr[idx][1]  = SZ(x);
      mp[x] = idx;idx++;
    }
    if (mp.find(y) == mp.end())
    {
      arr[idx][0]  = cost(y);
      arr[idx][1]  = SZ(y);
      mp[y] = idx;idx++;
    }
    u = mp[x];
    v = mp[y];
    adj[v].pb(u);
  }
  priority_queue<array<ll, 3>> pq;
  for (int i = 0; i < idx; i++)
  {
    dp[i][0] = arr[i][0];
    dp[i][1] = arr[i][1];
    pq.push({-arr[i][0], -arr[i][1], i});
  }
  while(!pq.empty())
  {
    auto cur = pq.top();
    cur[0] *= -1;
    cur[1] *= -1;
    int node = cur[2];
    pq.pop();
    for (int i: adj[node])
    {
      if (cur[0] < dp[i][0] || (cur[0] == dp[i][0] && cur[1] < dp[i][1]))
      {
        dp[i][0] = cur[0];
        dp[i][1] = cur[1];
        pq.push({-dp[i][0], -dp[i][1], i});
      }
    }
  }
  ll sum = 0;
  ll letters = 0;
  for (int i = 0; i < SZ(words); i++)
  {
    int u = mp[words[i]];
    sum += dp[u][1];
    letters += dp[u][0];
  }
  cout << letters <<" " << sum <<"\n";
}
