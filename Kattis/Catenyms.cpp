// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9, M = N * N;
int head[N], to[M], nxt[M], deg[N], edge[M], ans[M], I[M], vis[M], vid, sz, ne, n, m;
char str[N][22]; 
void init()
{
 memset(head, -1, 26 * sizeof head[0]);
 memset(deg, 0, 26 * sizeof deg[0]);  
 ne = sz = 0; 
 vid++; 
}
void addEdge(int u, int v, int idx)
{
 to[ne] = v;
 nxt[ne] = head[u];
 edge[ne] = idx; 
 head[u] = ne++;
}
void dfs(int u)
{
 for (int e = head[u]; ~e; e = nxt[e])
 {
  if (vis[e] == vid)continue; 
  vis[e] = vid;
  dfs(to[e]);
  ans[sz++] = edge[e];
 }
}
void test()
{
 scanf("%d", &n);
 init();
 int mn = 26; 
 for (int i = 0; i < n; i++)
 {
  scanf(" %s", str[i]);
  int u = str[i][0] - 'a';
  int v = str[i][strlen(str[i])-1] - 'a';
  deg[u]++;
  deg[v]--;  
  I[i] = i;
  mn = min(mn, u); 
 }
 sort(I, I+n, [](int i, int j)
 {
  return strcmp(str[i], str[j]) < 0; 
 });
 for (int i = n-1; ~i; i--)
 {
  int cur = I[i]; 
  int len = strlen(str[cur])-1;
  addEdge(str[cur][0] - 'a', str[cur][len] - 'a', cur); 
 }
 int st = mn, bad = 0;
 for (int i = 0, fl1 = 0, fl2 = 0; i < 26; i++)
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
   case 0:
   break;
   default:
   bad = 1; 
   break;
  }
 }
 dfs(st);
 if (bad || (sz != n))
 {
  printf("***\n"); 
  return; 
 }
 for (int i = sz-1; ~i; i--)
  printf("%s%c", str[ans[i]], (i? '.': '\n')); 
}
int main()
{
 int t;
 scanf("%d", &t); 
 while(t--)
  test(); 
}
