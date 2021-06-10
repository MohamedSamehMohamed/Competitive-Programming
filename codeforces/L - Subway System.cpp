// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
vector<string> get(string x)
{
  vector<string> v;
  string cur = "";
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] == ' ')
    {
      v.push_back(cur);
      cur = "";
    }else
      cur += x[i];
  }
  v.push_back(cur);
  return v;
}
map<string, vector<string>> adj;
int main()
{
  string dst = "Hotel";
  string cur = "Airport";
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
    string x;
    getline(cin, x);
    vector<string> v = get(x);
    for (int j = 1; j < v.size(); j++)
    {
      adj[v[0]].push_back(v[j]);
      adj[v[j]].push_back(v[0]);
    }
  }
  queue<pair<string, int>> q;
  q.push({cur, 0});
  map<string, int> vis;
  vis[cur] = 1;
  while(!q.empty())
  {
    auto node = q.front();
    q.pop();
    //cout << node.first << '\n';
    if (node.first == dst)
    {
      cout << node.second << '\n';
      return 0;
    }
    for (auto i: adj[node.first])
    {
      if (vis.find(i) != vis.end())continue;
      vis[i] = 1;
      q.push({i, node.second+1});
    }
  }
}
