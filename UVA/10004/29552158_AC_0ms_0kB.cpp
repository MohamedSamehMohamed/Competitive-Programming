// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 203, M = 2 * N; 
int color[N], head[N], to[M], nxt[M], ne, n; 
void init()
{
 memset(head, -1, n * sizeof head[0]);
 memset(color, -1, n * sizeof color[0]); 
 ne = 0; 
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
bool Bi()
{
 color[0] = 0;
 queue<int> q;
 q.push(0);
 while(!q.empty())
 {
  int u = q.front();
  q.pop();
  for (int e = head[u]; ~e; e = nxt[e])
  {
   int v = to[e];
   if (color[v] == -1)
   {
    color[v] = color[u] ^ 1;
    q.push(v); 
   }else if (color[v] == color[u])
    return 0;
  }
 }
 return 1; 
}
int main()
{
 while(scanf("%d", &n) && n)
 {
  init();
  int e, u, v;scanf("%d", &e);
  while(e--)
  {
   scanf("%d%d", &u, &v); 
   addBiEdge(u, v); 
  }
  printf("%s\n", (Bi()? "BICOLORABLE.": "NOT BICOLORABLE."));
 }
}
