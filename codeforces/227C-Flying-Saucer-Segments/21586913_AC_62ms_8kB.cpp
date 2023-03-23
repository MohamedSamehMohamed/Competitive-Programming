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
int n , m ;
ll mypow(int a , int b )
{
    if (b == 0 )return 1 ;
    if (b == 1 )return a ;
    if (b & 1 )return (1LL * a%m * mypow(a , b-1 )%m)%m;
    ll ret = mypow(a , b/2 )%m;
    ret = (ret * ret )%m;
    return ret ;
}
int main()
{
cin >> n >> m ;
ll ans = mypow(3 , n )%m - 1  ;
if (ans == -1 ) ans = m-1 ;
printf ("%lld\n" , ans );
}
