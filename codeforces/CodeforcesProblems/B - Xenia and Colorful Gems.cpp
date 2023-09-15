// Author : Mohamed sameh
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
int sz[3];
vector<int> v[3];
ll cal(int x, int y, int z)
{
 ll X = 1LL * (x-y) * (x-y);
 ll Y = 1LL * (y-z) * (y-z);
 ll Z = 1LL * (z-x) * (z-x);
 return X + Y + Z;
}
int main()
{
 int t;
 cin >> t;
 while(t--)
 {
  cin >> sz[0] >> sz[1] >> sz[2];
  for (int i = 0; i < 3; i++)
  {
   v[i].clear();
   v[i] = vector<int>(sz[i]);
   for (int &j: v[i])cin >> j;
   sort(all(v[i]));
  }
  vector<int> p;
  for (int i = 0; i < 3; i++)p.pb(i);
  ll ans = -1;
  do{
   int i = p[0];
   int j = p[1];
   int k = p[2];
   for (int c: v[i])
   {
    auto it1 = lower_bound(all(v[j]), c);
    auto it2 = upper_bound(all(v[k]), c);
    if (it1 == v[j].end() || it2 == v[k].begin())continue;
    it2--;
    ll cur = cal(c, *it1, *it2);
    if (ans == -1)ans = cur;
    ans = min(ans, cur);
   }
  }while(next_permutation(all(p))); 
  cout << ans << '\n';
 }
}
