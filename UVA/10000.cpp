// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 105, M = N * N;
int head[N], dp[N], to[M], nxt[M], ne, n, st;
void init()
{
 memset(dp, -1, n * sizeof dp[0]); 
 memset(head, -1, n * sizeof head[0]);
 ne = 0;
}
void addEdge(int u, int v)
{
 to[ne] = v; 
 nxt[ne] = head[u];
 head[u] = ne++; 
}
int dfs(int u)
{
 if (u == st) return 0;
 int &ret = dp[u]; 
 if (~ret)return ret;
 ret = -M*M;
 for (int e = head[u]; ~e; e = nxt[e])
 {
  int v = to[e];
  ret = max(ret, 1 + dfs(v));
 }
 return ret; 
} 
int main()
{
 int ti = 1;
 while(scanf("%d", &n) && n)
 {
  init();
  int u, v;
  scanf("%d", &st);st--; 
  while(scanf("%d%d", &u, &v) && (u||v))
  {
   u--;v--; 
   addEdge(v, u); 
  }
  int mx = -1;
  int ans = -1; 
  for (int i = 0; i < n; i++)
  {
   int cur = dfs(i); 
   if (cur > mx)
   {
    ans = i;
    mx = cur; 
   }
  }
  printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ti++, st+1, mx, ans+1); 
 }
}

