// Author : Mohamed Sameh
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
const int N = 1e5+9;
int par[N], size[N], n, m, q;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  if (size[u] + size[v] > m)return;
  par[u] = v;
  size[v] += size[u];
}
int main()
{
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
  {
    par[i] = i;size[i] = 1;
  }
  while(q--)
  {
    char type;
    int u, v;
    cin >> type >> u;
    if (type == 'S')
    {
      cout << size[get_par(--u)] << '\n';
      continue;
    }
    cin >> v;
    if (type == 'A')uni(--u, --v);
    else
    {
      cout << (get_par(--u) == get_par(--v) ? "Yes\n" : "No\n");
    }
  }
}
