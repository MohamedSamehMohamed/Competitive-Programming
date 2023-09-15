// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9, M = 2 * N;
int vis[N], head[N], to[M], nxt[M], edge[M], ne, n, k, d;
queue<pair<int, int>> q; 
void init()
{
 memset(head, -1, n * sizeof head[0]); 
 ne = 0; 
}
void addEdge(int u, int v, int p)
{
 to[ne] = v; 
 nxt[ne] = head[u]; 
 edge[ne] = p;
 head[u] = ne++; 
}
void addBiEdge(int u, int v, int p)
{
 addEdge(u, v, p);
 addEdge(v, u, p); 
}
int main()
{
 scanf("%d%d%d", &n, &k, &d);
 init();
 for (int i = 0; i < k; i++)
 {
  int x;scanf("%d", &x);x--; 
  q.push({x, -1}); 
 }
 for (int i = 0; i < n-1; i++)
 {
  int u, v; 
  scanf("%d%d", &u, &v); 
  u--;v--; 
  addBiEdge(u, v, i+1); 
 }
 set<int> ans;
 while(!q.empty())
 {
  int cur = q.front().first;
  int p = q.front().second;
  q.pop();
  if (vis[cur])continue;
  vis[cur] = 1; 
  for (int e = head[cur]; ~e; e = nxt[e])
  {
   int v = to[e];
   if (v == p)continue; 
   if (vis[v])
   {
    ans.insert(edge[e]); 
    continue; 
   }
   q.push({v, cur}); 
  }
 }
 printf("%ld\n", ans.size());
 for (int i: ans)
  printf("%d ", i);
 printf("\n"); 
 
}
