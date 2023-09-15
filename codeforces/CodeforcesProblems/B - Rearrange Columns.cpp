// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int n;
string x[2];
bool vis[1009][1009];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
string ans[2];
void dfs(int i, int j)
{
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++)
  {
    int nx = i + dx[k];
    int ny = j + dy[k];
    if (min(nx, ny) < 0 || nx >= 2 || ny >= n || vis[nx][ny] || ans[nx][ny] == '.')continue;
    dfs(nx, ny);
  }
}
int main()
{
  cin >> x[0] >> x[1];
  n = x[0].size();
  map<string, int> mp;
  for (int i = 0; i < n; i++)
  {
    string cur = "";
    cur += x[0][i];
    cur += x[1][i];
    mp[cur]++;
  }
  ans[0] = ans[1] = "";
  string order[] = {"..", "#.", "##", ".#"};
  for (auto i: order)
  {
    while(mp[i] > 0)
    {
      mp[i]--;
      ans[0] += i[0];
      ans[1] += i[1];
    }
  }
  int cnt = 0;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (vis[i][j] || ans[i][j] == '.')
        continue;
      dfs(i, j);
      cnt++;
    }
  }
  if (cnt != 1)
  {
    cout << "NO\n";
  }else
  {
    cout <<"YES\n";
    cout << ans[0] <<"\n" << ans[1] <<"\n";
  }
  /*
  # . # .
  # . . #
  */
}
