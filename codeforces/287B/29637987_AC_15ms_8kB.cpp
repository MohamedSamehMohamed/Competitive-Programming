// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo (){fflush(stdout);}

using namespace std ;

int main ()
{
    ll n , k ;
    cin >> n >> k ;
    k--;
    ll sum = ((k +1 ) * k)/2;
    int l = 1 , r = k  , m , ans = -1 ;
    while (l <= r )
    {

        m = (l+r)>>1;
        ll cursum = 1 + sum - (1LL*(m+1)*(m))/2;

        if (cursum == n )
        {
            ans = k - m   ;
            break;
        }else if (cursum < n )
        {
            if (n - cursum <= m )
            {
                ans = k - m + 1 ;
                break;
            }
            r= m -1 ;
        }else
        {
           l = m+1 ;
        }
    }
    cout << ans <<"\n";
    return 0;
}