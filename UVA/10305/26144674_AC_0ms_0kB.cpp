// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 100;
int n, k;
vector<int> adj[N];
stack<int> sk;
bool vis[N];
void dfs(int u)
{
  vis[u] = 1;
  for (int i : adj[u])
    if (!vis[i])dfs(i);
  sk.push(u);
}
int main()
{

  while(~scanf("%d%d", &n, &k)){
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++)adj[i].clear();
  for (int i = 0; i < k; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].pb(v);
  }
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])dfs(i);
  }
  while(!sk.empty())
  {
    printf("%d", sk.top()+1);
    sk.pop();
    if (!sk.empty())printf(" ");
  }
  printf("\n");
}
}
