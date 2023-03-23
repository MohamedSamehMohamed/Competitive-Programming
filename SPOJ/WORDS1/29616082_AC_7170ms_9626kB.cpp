// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int head[26], to[N], nxt[N], vis[N], deg[26], vid, ne, sz, n;
char x[1009]; 
void init()
{
 memset(head, -1, 26 * sizeof head[0]);
 memset(deg, 0, 26 * sizeof deg[0]);
 ne = sz = 0;
 vid++; 
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
  if (vis[e] == vid)continue; 
  vis[e] = vid;
  dfs(to[e]);
  sz++; 
 }
}
void test()
{
 init(); 
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
 {
  scanf(" %s", x);
  int u = x[0] - 'a';
  int v = x[strlen(x)-1] - 'a';
  deg[u]++;
  deg[v]--; 
  addEdge(u, v); 
 }
 bool bad = 0; 
 int st = -1;
 for (int i = 0; i < 26; i++)
 {
  if (abs(deg[i]) > 1) bad = 1; 
  if (deg[i] == 1)
  {  
   if (~st)
    bad = 1;
   st = i; 
  }
 }
 dfs(st);
 if (bad || n != sz)
 printf("The door cannot be opened.\n"); 
  else 
 printf("Ordering is possible.\n"); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
