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
ll M ;
ll mypow(int a , int b )
{
    if (b == 0 )return 1 ;
    if (b == 1 )return a ;
    if (b & 1 )return (1LL * a%M * mypow(a , b-1 )%M)%M;
    ll ret = mypow(a , b/2 )%M;
    ret = (ret * ret )%M;
    return ret ;
}
int main()
{
ll a , b ;
while (~scanf ("%lld%lld%lld" , &a , &b ,&M ))
{
    printf ("%lld\n" , mypow(a , b )%M);
}

}
