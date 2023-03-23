// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int main()
{
    ll n , m ;
    scanf ("%lld%lld" , &n ,&m );
    ll ans = n * m ;
    if (min(n , m) > 1 )
    {
        ans = ans - (  2*m + 2*n - 4  );
    }else if (n != m && min (m,n) == 1 )
    ans-=2 ;
    printf ("%lld\n" ,ans );


}
