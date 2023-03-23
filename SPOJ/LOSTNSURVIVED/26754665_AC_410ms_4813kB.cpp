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
int par[N], size[N], frq[N], n, q;
set<int> st;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  if(--frq[size[u]] == 0)st.erase(size[u]);
  if(--frq[size[v]] == 0)st.erase(size[v]);
  par[u] = v;
  size[v] += size[u];
  if (++frq[size[v]] == 1)st.insert(size[v]);
}
int query()
{
  if (SZ(st) == 1)return 0;
  auto beg = st.begin();
  auto en = st.end();
  en--;
  return *en - *beg;
}
int main()
{
  for (int i = 0; i < N; i++)
  {
    par[i] = i;
    size[i] = 1;
  }
  cin >> n >> q;
  frq[1] = n;
  st.insert(1);
  for (int i = 0; i < q; i++)
  {
    int u, v;
    cin >> u >> v;
    uni(--u, --v);
    cout << query() << '\n';
  }
}
