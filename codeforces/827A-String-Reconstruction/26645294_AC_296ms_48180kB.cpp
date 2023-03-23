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
const int N = 2e6+9;
int par[N], n, mx;
string x, ans;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
int main()
{
  FAST
  cin >> n;
  for (int i = 0; i < N; i++)par[i] = i;
  ans = string(N, 'a');
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    int len, idx;
    cin >> len;
    while(len--)
    {
      cin >> idx;
      idx--;
      int st = idx;
      int en = idx + SZ(x)-1;
      mx = max(mx, idx + SZ(x));
      st = get_par(st);
      while(st <= en)
      {
        ans[st] = x[st - idx];
        par[st] = get_par(st+1);
        st = get_par(st+1);
      }
    }
  }
  cout << ans.substr(0, mx) <<"\n";

}
