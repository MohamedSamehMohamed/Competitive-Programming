// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n; 
vector<int> adj[N];
double ans; 
void dfs(int u = 0, int p = -1, double prop = 1, int d = 0)
{
 bool end = 1; 
 for (int i: adj[u])
 {
  if (i == p)continue;
  end = 0; 
  dfs(i, u, prop/(adj[u].size()-(p != -1)), d+1); 
 }
 ans += prop * d * end; 
}
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n-1; i++)
 {
  int u, v;
  scanf("%d%d", &u, &v);
  u--;v--;
  adj[u].push_back(v);
  adj[v].push_back(u); 
 }
 dfs(); 
 printf("%.9lf\n", ans); 
}