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
    int p , d  , f , c ;
    double t ;
    cin >> p >> d >> t >> f >> c ;
    int ans =0 ;
    while (p < d )
    {
        double rm = 1.0*p*t / (d-p) ;
        if (rm * d >= c )break ;
        t+=2 * rm + f ;
        ans++;
    }
    printf ("%d\n" ,ans );

}
