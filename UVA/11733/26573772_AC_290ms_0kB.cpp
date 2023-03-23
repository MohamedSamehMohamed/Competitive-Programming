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
const int N = 1e5+9;
int n, m;
vector<array<int, 3>> edges;
int par[N];
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
bool conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0;
  par[u] = v;
  return 1;
}
vector<pair<int,int>> points;
double dist(int i, int j)
{
  return sqrt(pow(points[i].f - points[j].f, 2) + pow(points[i].s-points[j].s, 2));
}
bool cmp(array<int,3> &a, array<int, 3> &b)
{
  if (a[0] != b[0])return a[0] < b[0];
  return a[1] > b[1];
}
int main()
{
  int T = 1;
  int t, C;
  cin >> t;
  while(t--)
  {
    cin >> n >> m >> C;

    for (int i = 0; i < N; i++)par[i] = i;
    edges.clear();
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      u--;v--;
      edges.pb({c, u, v});
    }
    int ans = 0, cnt = 0;
    set<int> st;
    for (int i = 0; i < SZ(edges); i++)
    {
      conect(edges[i][1], edges[i][2]);
    }
    for (int i = 0; i < n; i++)st.insert(get_par(i));
    int cur = n;
    map<int,int> mp;
    for (int i: st)
    {
      mp[i] = cur;
      cur++;
    }
    for (int i = 0; i < n; i++)edges.pb({C, mp[get_par(i)], i});
    for (int i = 0; i < N; i++)par[i] = i;
    sort(all(edges), cmp);

    for (int i = 0; i < SZ(edges); i++)
    {
      if (conect(edges[i][1], edges[i][2]))
      {
        ans += edges[i][0];
        if (edges[i][1] >= n)cnt++;
      }
    }
    cout <<"Case #" << T++<<": ";
    cout << ans <<" " << cnt <<"\n";
  }
}
