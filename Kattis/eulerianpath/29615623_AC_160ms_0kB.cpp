// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9, M = N * N;
int head[N], to[M], nxt[M], deg[N], ans[M], vis[M], vid, sz, ne, n, m;
void init()
{
 memset(head, -1, n * sizeof head[0]);
 memset(deg, 0, n * sizeof deg[0]);  
 ne = sz = 0; 
 vid++; 
}
void addEdge(int u, int v)
{
 to[ne] = v;
 nxt[ne] = head[u];
 head[u] = ne++; 
}
void addBiEdge(int u, int v)
{
 addEdge(u, v);
 addEdge(v, u); 
}
void dfs(int u)
{
 for (int e = head[u]; ~e; e = nxt[e])
 {
  if (vis[e] == vid)continue; 
  vis[e] = vid;
  dfs(to[e]); 
 }
 ans[sz++] = u; 
}
void test()
{
 init();
 for (int i = 0; i < m; i++)
 {
  int u, v; 
  scanf("%d%d", &u, &v); 
  addEdge(u, v);
  deg[u]++;
  deg[v]--; 
 }
 int st = 0, bad = 0;
 for (int i = 0, fl1 = 0, fl2 = 0; i < n; i++)
 {
  switch(deg[i])
  {
   case 1:
   if (fl1++)bad = 1;
   st = i; 
   break;
   case -1:
   if (fl2++)bad=1; 
   break;
   default:
   break;
  }
 }
 dfs(st);
 if (bad || (sz != m+1))
 {
  printf("Impossible\n"); 
  return; 
 }
 for (int i = sz-1; ~i; i--)
  printf("%d%c", ans[i], (i? ' ': '\n')); 
}
int main()
{
 while(scanf("%d%d", &n, &m) && (n||m))
  test(); 
}
