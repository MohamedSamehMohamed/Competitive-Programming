// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
string g[102];
string p = "ICPCASIASG";
int n;
int vis[102][102];
bool can(int i, int j, int x, int y, int idx)
{
  if (min(i, j) < 0 || max(i, j) >= n)return 0;
  if (g[i][j] != p[idx])return 0;
  i++;j++;x++;y++;
  int dist = (i - x)*(i - x) + (j - y)*(j - y);
  return (dist == 5);
}
bool ok(int x, int y)
{
  queue<array<int,3>> q;
  q.push({x, y, 1});
  while(!q.empty())
  {
    auto cur = q.front();
    q.pop();
    if (cur[2] == p.size())return 1;
    for (int i = cur[0]-5; i < cur[0]+5; i++)
      for (int j = cur[1] - 5; j < cur[1] + 5; j++)
        if (can(i, j, cur[0], cur[1], cur[2]))
        {
          q.push({i, j, cur[2]+1});
        }
  }
  return 0;

}
int main()
{
  cin >> n;
  string x;
  cin >> x;
  int idx = 0;
  int i = 0;
  while(i + n <= n * n)
  {
    g[idx] = x.substr(i, n);
    i += n;
    idx++;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (g[i][j] == 'I')
        if (ok(i, j))
        {
          cout <<"YES\n";
          return 0;
        }
  cout <<"NO\n";
}
// me 