// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> adj[N];
int root, partiy, leavs, n;
void dfs(int u = root, int p = -1, int h = 0)
{
 if (adj[u].size() == 1)
  partiy |= (1<<h);
 leavs -= (adj[u].size() == 1);   
 bool non = (~p? (adj[u].size() != 1 && adj[p].size() == 1): 0);
 for (int i: adj[u])
  if (i != p)
  {
   non |= (adj[u].size() != 1 && adj[i].size() == 1); 
   dfs(i, u, h^1); 
  }
 leavs += non; 
}
int main()
{
 scanf("%d", &n);
 for (int i = 0; i + 1 < n; i++)
 {
  int u, v;
  scanf("%d%d", &u, &v);
  u--;v--;
  adj[u].push_back(v);
  adj[v].push_back(u); 
 } 
 for (int i = 0; i < n; i++)
  if (adj[i].size() == 1)
   root = i; 
 dfs();
 int mn = 3;
 // if all distances is even 
 if (partiy == 1) mn = partiy; 
 int mx = leavs + n - 1;
 printf("%d %d\n", mn, mx);
}
