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
int n , h , mx ;
ll ans ;
vector <int>  a ;
int main ()
{
scanf ("%d%d" , &n ,&h );
for (int i =0 ; i < n ;i++)
{
  int u , v ;
  scanf ("%d%d" , &u  , &v );
  a.pb(v);
  mx = max (mx , u );
}
sort(all(a));
for (int i = n-1 ; i >= 0 ; i--)
{
  if (h <= 0 )break;
  if (a[i] >= mx )
  {
    ans++;
    h-=a[i];
  }
}
if (h > 0 )ans += h / mx + ( h %mx != 0);
printf ("%lld\n" ,ans );



  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
