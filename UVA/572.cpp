// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 109; 
int n, m, vis[N][N], vid;
char x[N][N]; 
bool valid(int i, int j)
{
 return min(i, j) >= 0 && i < n && j < m; 
}
void dfs(int dx, int dy)
{
 vis[dx][dy] = vid;
 for (int i = -1; i <= 1; i++)
  for (int j = -1; j <= 1; j++)
  {
   if (!valid(dx+i, dy+j) || vis[dx+i][dy+j] == vid|| x[dx+i][dy+j] != '@')continue; 
   dfs(dx+i, dy+j); 
  }
}
int main()
{
 while(scanf("%d%d", &n, &m) && n)
 {
  for (int i = 0; i < n; i++)
   scanf(" %s", x[i]);
  vid++;
  int ans = 0;
  for (int i = 0; i < n; i++)
   for (int j = 0; j < m; j++)
   {
    if (x[i][j] != '@' || vis[i][j] == vid)
     continue; 
    ans++;
    dfs(i, j); 
   }
  printf("%d\n", ans);
 }
}


