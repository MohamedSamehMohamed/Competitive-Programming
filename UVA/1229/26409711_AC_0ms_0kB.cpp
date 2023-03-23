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
const int N = 3009;
vector<int> adj[N], rev[N], SCC[N];
stack<int> order;
int vis[N];
int n, m, id;
map<string, int> wordTonumber;
map<int, string> numerToword;
vector<string> Extract(string x)
{
  vector<string> ret;
  string cur = "";
  for (int i = 0; i < SZ(x); i++)
  {
    if (x[i] == ' ' || i+1 == SZ(x))
    {
      if (i+1 == SZ(x))cur += x[i];
      ret.pb(cur);
      cur = "";
      continue;
    }
    cur += x[i];
  }
  return ret;
}
int get_number(string x)
{
  if (wordTonumber.find(x) == wordTonumber.end())
  {
    wordTonumber[x] = SZ(wordTonumber);
    numerToword[SZ(wordTonumber)-1] = x;
  }
  return wordTonumber[x];
}
void dfs(int u)
{
  vis[u] = id;
  for (int i : adj[u])
    if (vis[i] != id)
      dfs(i);
  order.push(u);
}
int idx;
void dfs2(int u)
{
  vis[u] = id;
  for (int i : rev[u])
    if (vis[i] != id)
      dfs2(i);
  SCC[idx].pb(u);
}
vector<string> ans;
void dfs3(int u)
{
  vis[u] = id;
  for (int i : adj[u])
    if (vis[i] != id)
      dfs3(i);
  ans.pb(numerToword[u]);
}
int main()
{
  FAST
  while(cin >> n && n){
  ans.clear();
  for (int i = 0; i <= n; i++){
    adj[i].clear();
    rev[i].clear();
    SCC[i].clear();
  }
  order = stack<int>();
  wordTonumber.clear();
  numerToword.clear();
  set<pair<int,int>> dup;
  for (int i = 0; i < n; i++)
  {
    string x = "";
    while(SZ(x) == 0)getline(cin, x);
    vector<string> line = Extract(x);
    int u, v;
    u = get_number(line[0]);
    for (int j = 1; j < SZ(line); j++)
    {
      v = get_number(line[j]);
      if (dup.find({u, v}) == dup.end()){
      adj[u].pb(v);
      rev[v].pb(u);
      dup.insert({u, v});
    }
    }
  }
  id++;
  for (int i = 0; i < SZ(wordTonumber); i++)
    if (vis[i] != id)
      dfs(i);
  id++;
  idx = 0;
  while(!order.empty())
  {
    int cur = order.top();
    order.pop();
    if (vis[cur] == id)continue;
    dfs2(cur);
    idx++;
  }
  id++;
  for (int i = 0; i < idx; i++)
  {
    if (SZ(SCC[i]) > 1 && vis[SCC[i][0]] != id)
      dfs3(SCC[i][0]);
  }
  cout << SZ(ans) <<"\n";
  sort(all(ans));
  for (int i = 0; i < SZ(ans); i++)
    cout << ans[i] <<" \n"[i+1 == SZ(ans)];
  }
}
