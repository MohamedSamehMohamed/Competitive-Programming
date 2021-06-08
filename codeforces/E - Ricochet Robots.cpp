// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int n, w, h, l;
char a[12];
string x[12];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
map<string, bool> seen;
struct node{
  string g[10];
  int op, tarx, tary;
  void build()
  {
    op = 0;
    for (int i = 0; i < h; i++)
    {
      g[i] = "";
      for (int j = 0; j < w; j++)
      {
        if (x[i][j] == 'X')
        {
          tarx = i;
          tary = j;
          x[i][j] = '.';
        }
        g[i] += x[i][j];
      }
    }
  }
  void build(node cur)
  {
    op = cur.op;
    tarx = cur.tarx;
    tary = cur.tary;
    for (int i = 0; i < h; i++)
    {
      g[i] = "";
      for (int j = 0; j < w; j++)
      {
        g[i] += cur.g[i][j];
      }
    }
  }
  bool can(int x, int y)
  {
    return  !(min(x, y) < 0 || x >= h || y >= w || g[x][y] != '.');
  }
  bool move(int x, int y, int idx)
  {
    int nx = x + dx[idx];
    int ny = y + dy[idx];
    bool ok = 0;
    while(can(nx, ny))
    {
      ok = 1;
      swap(g[x][y], g[nx][ny]);
      x = nx;
      y = ny;
      nx += dx[idx];
      ny += dy[idx];
    }
    op += ok;
    return ok;
  }
  bool reach()
  {
    return (g[tarx][tary] == '1');
  }
  bool dup()
  {
    string cur = "";
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cur += g[i][j];
    if (seen.find(cur) != seen.end()){
      return 1;
    }
    seen[cur] = 1;
    return 0;
  }
};
void solve()
{
  queue<node> q;
  node cur;
  cur.build();
  q.push(cur);
  while(!q.empty())
  {
    cur = q.front();
    q.pop();
    if (cur.op > l)continue;
    if (cur.reach())
    {
      printf("%d\n", cur.op);
      return;
    }
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
      {
        if (cur.g[i][j] == '.' || cur.g[i][j] == 'W')continue;
        node tem;
        tem.build(cur);
        for (int k = 0; k < 4; k++)
        {
          if (tem.move(i, j, k))
          {
            if (!tem.dup())
              q.push(tem);
            tem.build(cur);
          }
        }
      }
 
  }
  printf("NO SOLUTION\n");
}
int main()
{
  scanf("%d%d%d%d", &n, &w, &h, &l);
  for (int i = 0; i < h; i++)
  {
    scanf(" %s", a);
    x[i] = a;
  }
  solve();
}
