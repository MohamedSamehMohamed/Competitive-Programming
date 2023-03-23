// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m, st, vis[N][N], dist[N][N], vid;
char x[N][N];
bool valid(int i, int j)
{
 return min(i, j) >= 0 && i < n && j < m; 
}
void nxt(int &dx, int &dy)
{
 if (x[dx][dy] == 'N')
  dx--;
 else if (x[dx][dy] == 'S')
  dx++;
 else if (x[dx][dy] == 'E')
  dy++;
 else 
  dy--; 
}
void dfs(int dx, int dy, int stps = 0)
{
 if (!valid(dx, dy))
 {
  printf("%d step(s) to exit\n", stps); 
  return; 
 }
 dist[dx][dy] = stps; 
 vis[dx][dy] = vid; 
 nxt(dx, dy);
 if (valid(dx, dy) && vis[dx][dy] == vid)
 {
  printf("%d step(s) before a loop of %d step(s)\n", dist[dx][dy], stps - dist[dx][dy] + 1);
  return;
 }
 dfs(dx, dy, stps+1); 
}
int main()
{
 while(scanf("%d%d%d", &n, &m, &st) && (n+m+st))
 {
  for (int i = 0; i < n; i++)
   scanf(" %s", x[i]);
  vid++; 
  dfs(0, st-1);
 }
}
