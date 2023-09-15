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
const int N = 3e5+9;
int n, m, par[N], win[N];
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i <= n; i++){
    win[i] = i;
    par[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int l, r, x;
    cin >> l >> r >> x;
    l--;r--;x--;
    l = get_par(l);
    while(l <= r)
    {
      if (win[l] == l && l != x)
      {
        win[l] = x;
        par[l] = par[l+1];
      }
      l = get_par(l+1);
    }
  }
  for (int i = 0; i < n; i++)
    cout << (win[i] == i? 0: win[i]+1) <<" ";
  cout <<"\n";
}
