// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf("%d" , &n )
void fo (){fflush(stdout);}
using namespace std;
ll fact (int x ){return (x <= 1 ? 1 : 1LL * x * fact (x-1));}
vector <int> adj[9];
int n , m ;
int sol (int cur , map <int,int> mp )
{
  if (SZ(mp) == n )
  {
    return 1 ;
  }
  int ans = 0 ;
  for (auto u : adj[cur])
  {
    if (mp.find(u) == mp.end())
    {
      map <int ,int >tem = mp ;
      tem[u] = 1 ;
      ans += sol (u , tem );
    }
  }
  return ans ;
}
int main ()
{
cin >> n >> m ;
for (int i=0 ;i < m ;i++)
{
  int u , v;
  cin >> u >> v ;
  adj[u].pb(v);
  adj[v].pb(u);
}
map <int , int > mp ;
mp[1] = 1 ;
cout << sol(1,mp) <<"\n";
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
