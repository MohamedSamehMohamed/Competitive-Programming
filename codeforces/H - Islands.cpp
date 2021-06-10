// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 60;
int n, m;
string x[N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool Land;
int seen[N][N], id;
void explore(int r, int c)
{
  seen[r][c] = id;
  for (int i = 0; i < 4; i++)
  {
    int nx = r + dx[i];
    int ny = c + dy[i];
    if (min(nx, ny) < 0 || nx >= n || ny >= m || seen[nx][ny] == id)
      continue;
    if (x[nx][ny] == 'L')Land = 1;
    if (x[nx][ny] == 'C')
      explore(nx, ny);
  }
}
void paint(int r, int c, char ch)
{
  x[r][c] = ch;
  for (int i = 0; i < 4; i++)
  {
    int nx = r + dx[i];
    int ny = c + dy[i];
    if (min(nx, ny) < 0 || nx >= n || ny >= m || x[nx][ny] != 'C')
      continue;
    paint(nx, ny, ch);
  }
}
void dfs(int r, int c)
{
  x[r][c] = '#';
  for (int i = 0; i < 4; i++)
  {
    int nx = r + dx[i];
    int ny = c + dy[i];
    if (min(nx, ny) < 0 || nx >= n || ny >= m || x[nx][ny] != 'L')
      continue;
    dfs(nx, ny);
  }
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  id++; 
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (x[i][j] == 'C')
      {
        Land = 0;
        explore(i, j);
        paint(i, j, (Land? 'L' : 'W'));
      }
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (x[i][j] == 'L')
      {
        ans++;
        dfs(i, j);
      }
    }
  cout << ans << '\n';
}
