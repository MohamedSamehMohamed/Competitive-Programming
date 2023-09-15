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
vector<int> v[3];
vector<int> ans;
int a, b, c;
bool solve(int id = 0)
{
  if (id == 3)
  {
    if ( a == max(ans[0], ans[1]) && b == max(ans[0], ans[2]) && c == max(ans[1], ans[2]))
    {
      return 1;
    }
    return 0;
  }
  for (int i =0; i < SZ(v[id]); i++)
  {
    ans.pb(v[id][i]);
    if (solve(id+1))return 1;
    ans.pop_back();
  }
  return 0;
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    ans.clear();
    cin >> a >> b >> c;
    v[0].clear();
    v[1].clear();
    v[2].clear();
    v[0].pb(a);
    v[0].pb(b);
    v[1].pb(c);
    v[1].pb(a);
    v[2].pb(b);
    v[2].pb(c);
    int Mx = 1e9;
    for (int i = 0; i < 3; i++)
    {
      v[i].pb(1);
      v[i].pb(Mx);
    }
    if (solve())
    {
      cout <<"YES\n";
      cout << ans[0] <<" " << ans[1] <<" " << ans[2] <<"\n";
    }else
    {
      cout <<"NO\n";
    }
 
  }
}
