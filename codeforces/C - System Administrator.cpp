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
int main()
{
  int n, m, v;
  cin >> n >> m >> v;
  int mn = n-1;
  ll mx = 1 + (1LL * (n-2) * (n-1)) / 2;
  if (m < mn || m > mx)
  {
    cout <<"-1\n";
    return 0;
  }
 
  vector<int> vec;
  for (int i = 1; i <= n; i++)vec.pb(i);
  swap(vec[1], vec[v-1]);
  vector<pair<int,int>> ans;
  for (int i = 0; i + 1< n; i++)ans.pb({vec[i], vec[i+1]});
  int cur = 1;
  int idx = 2;
  while(SZ(ans) < m)
  {
    if (cur + idx >= n)
    {
      idx = 2;
      cur++;
    }
    ans.pb({vec[cur], vec[cur + idx]});
    idx++;
  }
  for (auto i: ans)
    cout << i.f <<" " << i.s <<"\n";
}
