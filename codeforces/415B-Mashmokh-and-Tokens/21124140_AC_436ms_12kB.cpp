// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo ()
{
    fflush(stdout);
}
using namespace std ;
int n , a , b ;
int main ()
{
    cin >> n >> a >> b ;
    for (int i =0 ; i < n ;i++)
    {
        int v ;
        cin >> v ;
        ll cur = 1LL * v * a ;
        cur /= b ;
        ll l =0 , r = v , m , ans = 0 ;
        while (l <= r )
        {
            m = (l+r)>>1LL;
            if ( (m * a)/b >= cur  )
                ans = m , r = m-1 ;
            else
                l = m+1 ;
        }
        cout << v - ans <<" " ;
    }

    return 0;
}
