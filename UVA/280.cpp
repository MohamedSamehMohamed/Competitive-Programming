// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 102, M = N * N; 
int head[N], to[M], nxt[M], vis[N], vid, ne, n;
void init()
{
 memset(head, -1, n * sizeof head[0]); 
 ne = 0; 
} 
void addEdge(int u, int v)
{
 to[ne] = v; 
 nxt[ne] = head[u];
 head[u] = ne++; 
}
void dfs(int u)
{
 for (int e = head[u]; ~e; e = nxt[e])
 {
  int v = to[e];
  if (vis[v] == vid)continue;
  vis[v] = vid;
  dfs(v); 
 }
}
int main()
{
 while(scanf("%d", &n) && n)
 {
  init();
  int u, v; 
  while(scanf("%d", &u) && u)
  {
   u--; 
   while(scanf("%d", &v) && v)
   {
    v--; 
    addEdge(u, v); 
   }
  }
  scanf("%d", &u); 
  while(u--)
  {
   scanf("%d", &v); v--;
   vid++;
   dfs(v);
   vector<int> bad;
   for (int i = 0; i < n; i++)
    if (vis[i] != vid)
     bad.push_back(i+1); 
   printf("%d", (int)bad.size());
   for (int i: bad)
    printf(" %d", i); 
   printf("\n"); 
  }
 }
}
