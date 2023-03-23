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
const int N = 2e5+9;
int n, m;
int size[N], par[N], deg[N];
vector<int> adj[N];
int get_par(int u)
{
  return u == par[u] ? u: par[u] = get_par(par[u]);
}
bool uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0 ;
  if (v < u)swap(u, v);
  par[u] = v;
  size[v] += size[u];
  return 1;
}
bool same(int u, int v)
{
  return get_par(u) == get_par(v);
}
void P()
{
  cout <<"\n\n";
  for (int i = 1; i <= n; i++)
    cout << get_par(i) <<" " << size[get_par(i)] <<"\n";
  cout <<"\n\n";
}
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    par[i] = i;
    size[i] = 1;
  }
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    if (u > v)swap(u, v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  bool con = 0;
  for (int i = 1; i <= n; i++)
  {
    if (SZ(adj[i]) == 0)
    {
      con = 1;
      break;
    }else if (SZ(adj[i]) == 1)
    {
      if (adj[i][0] == 1)
      {
        int st, en, p;
        st = 2;
        en = n;
        p = i;
        while(st <= en)
        {
          uni(p, st);
          if (st + 1 <= en && same(st, st + 1))
          {
            st = get_par(st + 1);
          }else
          st++;
        }
      }else if (adj[i][0] == n)
      {
        int st, en, p;
        st = 1;
        en = n-1;
        p = i;
        while(st <= en)
        {
          uni(p, st);
          if (st + 1 <= en && same(st, st + 1))
          {
            st = get_par(st + 1);
          }else
          st++;
        }
      }else
      {
        int st, en, p;
        st = 1;
        en = adj[i][0]-1;
        p = i;
        while(st <= en)
        {
          uni(p, st);
          if (st + 1 <= en && same(st, st + 1))
          {
            st = get_par(st + 1);
          }else
          st++;
        }
        st = adj[i][0]+1;
        en = n;
        while(st <= en)
        {
          uni(p, st);
          if (st + 1 <= en && same(st, st + 1))
          {
            st = get_par(st + 1);
          }else
          st++;
        }
      }

    }else
    {
      int st, en, p;
      adj[i].pb(0);
      adj[i].pb(n+1);
      sort(all(adj[i]));
      p = i;
      for (int j = 0; j + 1 < SZ(adj[i]); j++)
      {
        st = adj[i][j]+1;
        en = adj[i][j+1]-1;
        while(st <= en)
        {
          uni(p, st);
          if (st + 1 <= en && same(st, st + 1))
          {
            st = get_par(st + 1);
          }else
          st++;
        }
      }
    }
  }

  if (con)
  {
    cout << "1\n";
    cout << n <<"\n";
    return 0;
  }
  vector<int> ans;
  set<int> tk;
  for (int i = 1; i <= n; i++)
  {
    int p = get_par(i);
    if (tk.find(p) == tk.end())
    {
      ans.pb(size[p]);
      tk.insert(p);
    }
  }
  sort(all(ans));
  cout << SZ(ans) <<"\n";
  for (int i : ans)
    cout << i <<" ";
  cout <<"\n";
}
