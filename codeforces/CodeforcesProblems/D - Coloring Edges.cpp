// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 5e3+9;
int n, m;
vector<pair<int,int>> adj[N];
int col[N], ans[N], c;
void dfs(int u)
{
  col[u] = 1;
  for (auto i: adj[u])
  {
    if (!col[i.f])
    {
      dfs(i.f);
      ans[i.s] = 1;
    }else if (col[i.f] == 2)
    {
      ans[i.s] = 1;
    }else
    {
      ans[i.s] = 2;
      c = 1;
    }
  }
  col[u] = 2;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;v--;
    adj[u].pb({v, i});
  }
  for (int i = 0; i < n; i++)
    if (!col[i])
      dfs(i);
  cout << 1 + c << '\n';
  for (int i = 0; i < m; i++)
    cout << ans[i] << " \n"[ i + 1 == m];
 
}
