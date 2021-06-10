#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
const int N = 1e4 + 9, M = 105, SS = 1e6 + 9; 
long long Mx = 1e13; 
int n, m, k; 
vector<array<int,3>> adj[N]; 
int src, des;
int siev[SS]; 
long long dist[N][M];  
void dijkstra()
{
 dist[src][k] = 0; 
 priority_queue<pair<ll,pair<int,int>>> pq; 
 pq.push({0,{src, k}}); 
 while(!pq.empty())
 {
  auto cur = pq.top().second;
  pq.pop(); 
  int u = cur.first; 
  int rm = cur.second; 
  for (auto i: adj[u])
  {
   
   if (rm && dist[i[0]][rm-1] > dist[u][rm] + i[2]) 
   {
    dist[i[0]][rm-1] = dist[u][rm] + i[2]; 
    pq.push({-dist[i[0]][rm-1] ,{i[0] , rm-1}}); 
   }
   if (dist[i[0]][rm] > dist[u][rm] + i[1])
   {
    dist[i[0]][rm] = dist[u][rm] + i[1]; 
    pq.push({-dist[i[0]][rm] ,{i[0] , rm}});
   }
  }
 }
}
void Prepare()
{
 siev[0] = siev[1] = 1; 
 for (int i = 2; i < SS; i++)
 {
  for (int j = i; j < SS; j+=i)
  {
   if (siev[j] == 0)siev[j] = i; 
   siev[j] = min(siev[j], i);   
  }
 }
}
int getC(int x)
{
 int nx = x; 
 int best = x; 
 while(nx != 1)
 {
  int p = siev[nx];
  while(nx % p == 0)
   nx/=p; 
  best = min(best, x/p + 2 * p); 
 }
 return best; 
}
void init()
{
 for (int i = 0; i < n; i++)
  for (int j = 0; j <= k; j++)
   dist[i][j] = Mx; 
 for (int i = 0; i < n; i++)
  adj[i].clear(); 
}
void test()
{
 scanf("%d%d%d", &n, &m, &k); 
 init();
 for (int i =  0; i < m; i++)
 {
  int u, v, c; 
  scanf("%d%d%d", &u, &v, &c); 
  u--;v--;  
  adj[u].push_back({v, c, getC(c)});
  adj[v].push_back({u, c, getC(c)});
 }
 scanf("%d%d", &src, &des); 
 src--;des--; 
 dijkstra(); 
 long long ans = Mx; 
 for (int i = 0; i <= k; i++)
  ans = min(ans, dist[des][i]); 
 if (ans == Mx)ans = -1; 
 printf("%lld\n", ans);  
}
int main()
{
 Prepare(); 
 int t; 
 scanf("%d", &t); 
 while(t--)
 {
  test(); 
 }
}
/*
3 
3 4 2
1 2 15
1 3 20
2 3 24
1 3 18
1 3 
4 4 1
1 2 18
2 3 64
3 4 42 
1 3 36 
1 4 
4 4 10
1 2 2 
1 3 5
2 3 11
3 4 13
1 4
*/
