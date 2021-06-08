#include <bits/stdc++.h>
 
using namespace std;
const int N = 2e5 + 9; 
int n; 
vector<int> adj[N];
int main()
{
 scanf("%d", &n);
 for (int i = 0; i + 1< n; i++)
 {
  int u, v; 
  scanf("%d%d", &u, &v);
  u--;v--;
  adj[u].push_back(v);
  adj[v].push_back(u); 
 }
 int leafs = 0;
 for (int i = 0; i < n; i++)
  leafs += (adj[i].size() == 1);
 printf("%d\n", (leafs+1)/2); 
}
