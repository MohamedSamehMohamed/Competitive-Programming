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
int main ()
{
    int a , b , c , d;
    cin >> a >> b >> c >> d ;
    int A , B ;
    if (1.0*c/d < 1.0*a / b)
    {
        A = a*d - b*c ;
        B = a*d ;

    }else if (1.0*c /d > 1.0*a / b )
    {
        A = b*c - a*d ;
        B = b * c ;
    }else A = B = 0 ;
    int g = __gcd (A , B );
    if (g != 0 )A /= g , B/= g ;
    if (A == 0 )B = 1 ;
    cout << A <<"/"<<B<<"\n";
    return 0;
}
