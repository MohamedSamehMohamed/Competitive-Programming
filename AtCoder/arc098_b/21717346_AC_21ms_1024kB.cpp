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
const int M = 2e5 ;
int n ;
int a[M];
int main()
{
    scanf ("%d" , &n );
    for (int i =0 ; i < n ;i++)scanf ("%d" ,a +i );
    ll ans =0 ;
    ll sum =0 , xo =0 ;
    for (int i =0 , j =0 ; j < n ;j++)
    {
        sum += a[j];
        xo  ^= a[j];
        while (sum != xo )
        {
            sum -= a[i];
            xo ^= a[i];
            i++;
        }
        ans += (j - i + 1 );
    }
    printf ("%lld\n" ,ans );
}
