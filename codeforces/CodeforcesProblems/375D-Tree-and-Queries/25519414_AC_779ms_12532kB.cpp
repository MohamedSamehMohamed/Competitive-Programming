// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define MP make_pair
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e5 ;
int a[N],mo[2*N],st[N],en[N],frq[N],Inpath[N],idx,n,m;
int Q[N][3], order[N], ans[N];
vector<int> adj[N];
int StFrq[N+1];
set<int> St ;
void dfs (int u= 0, int p=0)
{
  st[u] = idx ;
  mo[idx++] = u ;
  for (int i : adj[u])if (i != p)dfs(i, u);
  en[u] = idx;
  mo[idx++]=u;
}
void add (int i)
{
  i = mo[i];
  Inpath[i]++;
  if (Inpath[i] == 2 )
  {
    if (--StFrq[ frq[a[i]] ] == 0)St.erase(frq[a[i]]);
    frq[a[i]]++;
    StFrq[frq[a[i]]]++;
    St.insert(frq[a[i]]);
  }
}
void remove(int i )
{
  i = mo[i];
  Inpath[i]--;
  if (Inpath[i] == 1 )
  {
    if (--StFrq[ frq[a[i]] ] == 0)St.erase(frq[a[i]]);
    frq[a[i]]--;
    StFrq[frq[a[i]]]++;
    St.insert(frq[a[i]]);
  }
}
int query(int x)
{
  int ans =0 ;
  auto it = St.lower_bound(x);
  while (it != St.end())
  {
    ans += StFrq[*it];
    it++;
  }
  return ans ;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m ;
    for (int i =0; i < n ;i++)
    {
      cin >> a[i];a[i]--;
    }
    for (int i =0; i < n-1 ;i++)
    {
      int u, v;
      cin >> u >> v;
      u--;v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    dfs();
    for (int i =0; i < m ;i++)
    {
      order[i] = i ;
      int u, val;
      cin >> u >> val;
      u--;
      Q[i][0] = st[u];
      Q[i][1] = en[u];
      Q[i][2] = val;
    }
    int sq = sqrt(idx);
    sort(order, order+m, [sq](int i, int j){
      return MP(Q[i][0]/sq , Q[i][1]) < MP(Q[j][0]/sq , Q[j][1]);
    });
    int l = 0 , r = -1;
    for (int i =0; i < m ;i++)
    {
      int cur = order[i];
      while (l > Q[cur][0])add(--l);
      while (r < Q[cur][1])add(++r);
      while (l < Q[cur][0])remove(l++);
      while (r > Q[cur][1])remove(r--);
      //cout << cur + 1 <<" " << Q[cur][0] <<" " << Q[cur][1] <<"\n";
      ans[cur] = query(Q[cur][2]);
    }
    for (int i =0; i < m ;i++)
    {
      cout << ans[i] <<"\n";
    }

}
