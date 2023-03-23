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
bool cmp (pair<int,int> a , pair<int,int> b )
{
    int i , j , k , l ;
    i = min (a.f , a.s );
    k = min (a.f*2 , a.s ) ;

    j = min (b.f , b.s );
    l = min (b.f*2 , b.s );
    k-=i;
    l-=j;
    return k > l ;
}
int main()
{
    int n , f ;
    scanf ("%d%d" , &n ,&f );
    vector<pair<int,int>> v(n);
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%d%d" , &v[i].f , &v[i].s );
    }
    sort(all(v)  , cmp );
    ll ans =0 ;
    for (int i =0 ; i < n ;i++)
    {
        if (f)
        {
           ans += min (v[i].f *  2, v[i].s );
           f--;
        }else
        {
            ans += min (v[i].f , v[i].s );
        }
    }
    printf ("%lld\n" ,ans );
}
