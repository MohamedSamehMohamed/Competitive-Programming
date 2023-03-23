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
const int N = 1e5, Lg=20;
int tour[2*N], st[2*N], en[2*N], spt[2*N][Lg],Log[2*N],dep[N], idx, idx1 ;
int a[N], Q[2*N][4], order[2*N], ans[2*N], frq[N+9], Inpath[N];
int mo[2*N];
vector<int> adj[N+9];
int n, m;
void dfs (int u=0, int p=0, int dp=0)
{
  dep[u] = dp;
  st[u] = idx;
  mo[idx1++]  = u;
  tour[idx++] = u ;
  for (int i : adj[u])
  {
    if (i == p)continue ;
    dfs(i, u, dp+1 );
    tour[idx++] = u ;
  }
  en[u] = idx1;
  mo[idx1++]=u;
}
void Sparse ()
{
  for (int i =0; i< idx ;i++)
  spt[i][0] = i ;
  for (int j = 1; j < Lg ;j++)
  {
    for (int i = 0 ; i + (1<<j) <= idx ;i++)
    {
      int L = spt[i][j-1];
      int R = spt[i+(1<<(j-1))][j-1];
      spt[i][j] = dep[tour[L]] < dep[tour[R]] ? L : R ;
    }
  }
}
int query (int u, int v)
{
  int sz = Log[v-u+1];
  int L = spt[u][sz];
  int R = spt[v-(1<<sz)+1][sz];
  return dep[tour[L]] < dep[tour[R]] ? L : R ;
}
int lca (int u, int v)
{
  u = st[u];
  v = st[v];
  if (u > v )swap(u, v);
  return tour[query(u, v)];
}
void update (int i)
{
    frq[a[mo[i]]]+=(Inpath[mo[i]] ? -1 : 1);
    Inpath[mo[i]] = !Inpath[mo[i]];
}
void init ()
{
  idx = idx1 = 0;
  for (int i =0; i <= n;i++)
  {
    frq[i] = Inpath[i] = 0;
    adj[i].clear();
  }
}
int main()
{

    for (int i = 2 ; i < 2*N ; i++)Log[i] = Log[i/2] + 1 ;
    while (~scanf("%d%d", &n, &m))
    {
      init();
      for (int i =0; i < n ;i++)
      {
        scanf("%d",a+i);
      }
      for (int i = 1; i < n ;i++)
      {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
      }
      dfs();
      Sparse();
      for (int i =0; i < m ;i++)
      {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--;v--;
        if (st[u] > st[v])swap(u, v);
        int l = lca(u, v);
        Q[i][2] = c;
        Q[i][3] = l;
        if (l == u)
        {
          u = st[u]+1;
          v = st[v];
        }else
        {
          u = en[u];
          v = st[v];
        }
        Q[i][0] = u;
        Q[i][1] = v;
        order[i] = i;
      }
      int sq = sqrt(idx1);
      sort(order, order+m,[sq](int i, int j){
        return MP(Q[i][0]/sq, Q[i][1]) < MP(Q[j][0]/sq, Q[j][1]);
      });
      int l=0, r= -1;
      for (int i =0; i < m ;i++)
      {
        int cur = order[i];
        while (l > Q[cur][0])update(--l);
        while (r < Q[cur][1])update(++r);
        while (l < Q[cur][0])update(l++);
        while (r > Q[cur][1])update(r--);
        frq[a[Q[cur][3]]]++;
        /*
        printf("qN:%d, L:%d R:%d LCA:%d\n",cur+1, Q[cur][0], Q[cur][1], Q[cur][3] );
        for (int j =1 ; j < 10; j++)
        printf ("%d " , frq[j]);
        printf ("\n");
        */
        ans[cur] = frq[Q[cur][2]];
        frq[a[Q[cur][3]]]--;
      }
      for (int i =0; i < m ;i++)
      {
        printf("%s\n",(ans[i]?"Find":"NotFind"));
      }
      printf ("\n");
    }
}
/*
7 5
5 6 1 1 7 3 5
1 2
1 7
2 3
2 5
3 4
3 6
3 7 5
3 7 1
3 7 6
3 7 1
7 5 7
*/
