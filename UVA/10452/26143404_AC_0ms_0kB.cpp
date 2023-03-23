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
const int N = 8;
string s = "IEHOVA#";
int dx[] = {-1,0, 0};
int dy[] = {0,1, -1};
string mp[] = {"forth", "right" , "left"};
bool vis[N][N];
string X[N];
int n, m;
stack<int> ans;
bool dfs(int x, int y, int cur)
{
  if (cur == SZ(s))return 1;
  for (int i = 0; i < 3; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (min(nx, ny) < 0 || nx == n || ny == m || vis[nx][ny] || X[nx][ny] != s[cur])continue;
    vis[nx][ny] = 1;
    if (dfs(nx, ny, cur+1))
    {
      ans.push(i);
      return 1;
    }
    vis[nx][ny] = 0;
  }
  return 0;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> X[i];
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (X[i][j] == '@')
          {
            dfs(i, j, 0);
            break;
          }
    while(!ans.empty())
    {
      printf("%s", mp[ ans.top() ].c_str());
      ans.pop();
      if (!ans.empty())printf(" ");
    }
    printf("\n");
  }
}
