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
    int n , m ;
    int x , y ;
    scanf ("%d%d%d%d" , &n ,&m ,&x ,&y );
    ll tot =0 ;
    int k ;
    scanf ("%d" , &k );
    while (k--)
    {
        int nx , ny ;
        scanf("%d%d" , &nx ,&ny );
        // Bad Code
        ll l = 0 , r = 2e9 , mid , ans = 0 ;
        while (l <= r )
        {
            mid = (l+r)>>1LL;
            ll X = mid*nx + x ;
            ll Y = mid * ny + y ;
            if (X <= n && Y <= m && min (X , Y) > 0 )
            {
                ans = mid ;
                l = mid+1;
            }else
            r = mid-1 ;
        }
        tot+=ans ;
        x += ans * nx ;
        y += ans * ny ;
    }
    printf ("%lld\n" ,tot );

}
