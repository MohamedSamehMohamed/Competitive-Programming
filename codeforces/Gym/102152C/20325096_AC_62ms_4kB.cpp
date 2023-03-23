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
ll pow (int a , int b , int p )
{
  if (!b)return 1 % p ;
  ll ret = 0 ;
  if (b % 2 == 0 )ret =pow (a , b/2  , p) % p ;
  ret = (ret * ret)%p;
  return ( b % 2 ? 1LL * a%p * pow (a  , b - 1 , p )%p :  ret  );
}
int main ()
{
  int t ;
  scanf ("%d" , &t );
  while (t--)
  {
    int n , m ;
    scanf ("%d%d" , &n ,&m );
    n+=m;
    printf ("%d\n" , (n % 2 ? 2 : 12 ));
  }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
