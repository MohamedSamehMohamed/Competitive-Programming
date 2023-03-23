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
int main ()
{
  int t ;
  cin >> t ;
  while (t--)
  {
    ll a , b ;
    cin >> a >> b ;
    ll g = __gcd (a , b );
    if (g != 1 )
    {
      cout << "Sim\n";
    }else
    {
      cout <<"Nao\n";
    }
  }

//  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
