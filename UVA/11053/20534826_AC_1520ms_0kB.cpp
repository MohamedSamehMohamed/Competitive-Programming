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
ll n , a ,b ;
int main ()
{
while (1)
{
  scanf ("%lld" , &n ); if (!n)break;
  scanf ("%lld%lld" , &a ,&b );
  map <int,int> mp ;
  int ans =n ;
  mp[0]++;
  for (ll i = 0 ;   ; )
  {
    i = (a%n * i%n * i%n + b%n)%n ;
    mp[i]++;
    if (mp[i] == 2 )ans--;
    if (mp[i] == 3 )break;
  }
  cout << ans <<"\n";
}
//cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
