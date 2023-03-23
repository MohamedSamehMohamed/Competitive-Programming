// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo (){fflush(stdout);}
using namespace std;
int n , m;
int main ()
{
    cin >> n >> m ;
    ll ans = 1LL * n * m ;
    ans -= 1LL * 2 * n + 1LL * 2 * m ;
    ans += 4 ;
    cout << abs(ans) <<"\n";

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
