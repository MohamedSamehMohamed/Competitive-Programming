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
ll x ;
vector <ll> divs ;
bool sive[10000000];
int main()
{
    for (int i = 2; i <= 1e7/i ;i++)
    {
        if (sive[i])continue ;
        for (int j = i*i ; j < 1e7 ; j+=i)sive[j] =1 ;
    }
    scanf ("%lld" , &x );
    if (x == 1 )
    {
        printf ("1\n0\n");
        return 0;
    }
    ll N = x;
    for (int i = 2 ; x != 1 && SZ(divs) < 3 && i < 1e7 ;i++)
    {
        if (sive[i] || x % i )continue ;
        while (x % i == 0 )
        {
            x/=i;
            divs.pb(i);
        }
    }
    if (x != 1 )divs.pb(x);
    if (SZ(divs) == 1 )
    {
        printf ("1\n0\n");
    }else if (1LL*divs[0] * divs[1] < N )
    {
        printf ("1\n%lld\n" , 1LL*divs[0] * divs[1]);
    }else
    printf ("2\n");
}
