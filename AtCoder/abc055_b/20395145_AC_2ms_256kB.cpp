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
int n ;
int main ()
{
  cin >> n ;
  ll ans = 1;
  int m = 1e9 + 7 ;
  for (int i = 2 ; i <= n ;i++)
  {
    ans = (ans * i );
    ans %= m ;
  }
  cout << ans <<"\n";
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
