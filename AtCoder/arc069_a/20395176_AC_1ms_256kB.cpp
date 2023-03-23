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
ll n , m ;
int main ()
{
  cin >> n >> m ;
  ll mn = min (n , m / 2 );
  ll ans = mn ;
  n -= mn ;
  m -= mn * 2 ;
  if (n == 0 )
  {
    ans += m / 4;
  }
  cout << ans <<"\n";
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
