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

int main ()
{
  int t ;
  scanf ("%d" , &t );
  while (t--)
  {
    ll l , r ;
    scanf ("%lld%lld" , &l , &r );
    ll ev  = r / 2 - ((l-1) / 2) ;
    ev = (r - l + 1) - ev ;
    if (ev % 2 == 0 )
    printf ("Even\n");
    else
    printf ("Odd\n");  
  }

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}