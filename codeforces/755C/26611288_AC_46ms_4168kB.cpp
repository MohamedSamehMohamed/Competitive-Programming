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
const int N = 1e4+9;
int par[N];
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u != v)par[u] = v;
}
int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)par[i] = i;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    x--;
    uni(i, x);
  }
  set<int> st;
  for (int i = 0; i < n; i++)st.insert(get_par(i));
  cout << SZ(st) <<"\n";
}
