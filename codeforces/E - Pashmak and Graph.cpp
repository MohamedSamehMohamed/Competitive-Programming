// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int n, m;
int dp[N], temp[N];
vector<array<int, 3>> edges; 
void solve(int l, int r)
{
 for (int i = l; i <= r; i++)
 {
  int u = edges[i][1];
  int v = edges[i][2];
  if (i == l)temp[v] = dp[u] + 1; 
  temp[v] = max(temp[v], dp[u] + 1);
 }
 for (int i = l; i <= r; i++)
 {
  int v = edges[i][2];
  dp[v] = max(dp[v], temp[v]); 
 }
}
int main()
{
 scanf("%d%d", &n, &m);
 for (int i = 0; i < m; i++)
 {
  int u, v, c;
  scanf("%d%d%d", &u, &v, &c);
  u--;v--;
  edges.push_back({c, u, v}); 
 }
 sort(edges.begin(), edges.end()); 
 for (int i = 0; i < m; i++)
 {
  int j = i+1;
  while(j < m && edges[j][0] == edges[i][0])
   j++;
  solve(i, j-1);
  i = j-1; 
 }
 int ans = *max_element(dp, dp+n);
 printf("%d\n", ans); 
}
