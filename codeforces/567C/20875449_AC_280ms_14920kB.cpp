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
int a[200000];
map <int ,int > mpl , mpr  ;

int main ()
{
    int n , k ;
    scanf ("%d%d" , &n ,&k );
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%d" , a+i );
        if (i)mpr[a[i]]++;
    }
    mpl[a[0]]++;
    ll ans = 0 ;
    for (int i = 1; i < n ;i++)
    {
        int prv = 0 ;
        mpr[ a[i] ]--;
        if (a[i] % k || 1LL * abs (a[i]) * k > 1e9 ){mpl[a[i]]++;continue ;}
        prv = a[i]/k;
        ans += 1LL * mpl[prv] * mpr[a[i]*k] ;
        mpl[ a[i] ]++;

    }
    printf ("%lld\n" , ans );


    return 0;
}
