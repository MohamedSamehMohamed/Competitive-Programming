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
#define debug(x) cout<<#x<<" = { "<<x<<" }\n"
void fo (){fflush(stdout);}
using namespace std;

int main ()
{
int n , k ;
cin >> n >> k ;
int need = n/2 + n % 2;
if (k >= need )
{
  printf ("10\n");
}else
{
  int row = min (n , 2 * k );
  ll tem = (n-row)*1LL*2 ;
  tem = tem / row + (tem % row != 0 ) ;

  ll ans = 10 + tem * 5   ;
  printf ("%lld\n" ,ans );
}
cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
