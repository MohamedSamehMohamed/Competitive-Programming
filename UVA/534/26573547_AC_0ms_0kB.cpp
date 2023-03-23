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
vector<pair<double, pair<int,int>>> edges;
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
int main()
{
  int T = 1;
  while(cin >> n && n)
  {
    for (int i = 0; i < n; i++)par[i] = i;
    edges.clear();
    points.clear();
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      points.pb({x, y});
    }
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        {
          edges.pb({ dist(i, j), {i, j} });
        }
    sort(all(edges));
    double ans = 0;
    for (int i = 0; i < SZ(edges) && get_par(0) != get_par(1); i++)
    {
      if (conect(edges[i].s.f, edges[i].s.s))
      {
        ans = max(ans, edges[i].f);
      }
    }
    cout <<"Scenario #" << T++ << "\n";
    cout <<"Frog Distance = ";
    printf("%.3f\n", ans);
    cout <<"\n";
  }
}
