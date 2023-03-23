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
    int t ;
    scanf ("%d" , &t );
    while (t--)
    {
        int n , m ;
        scanf ("%d%d" , &n ,&m );
        ll ans = 0 ;
        int bit = 0 ;
        while (n >= 2 && m >= 1 )
        {
            ans |= (1LL << bit ) | (1LL << (bit + 2) );
            bit += 3 ;
            n-=2;
            m--;
        }
        if (n == 1  && m )ans |= (1LL << bit ) , bit += 2, m--,n--;
        while (n)ans=(ans << 1LL) | 1 ,n--;
        printf ("%lld\n" , ans );
    }
    return 0;
}
