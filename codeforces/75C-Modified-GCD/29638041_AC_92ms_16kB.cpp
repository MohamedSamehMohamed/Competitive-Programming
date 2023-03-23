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
vector <int> v ;
int a , b , n ;
int solve (int L , int R )
{
    int l =0 , r = SZ(v)-1 , m ,cur = -1 ;
    while (l <= r)
    {
        m = (l+r)>>1;
        if (v[m] >= L && v[m] <= R )
        {
          cur = v[m];
          l = m+1 ;
          continue ;
        }
        if (v[m] < L )l = m+1 ;
        else
            r = m-1 ;
    }
    return cur ;
}
int main()
{
    scanf ("%d%d%d" , &a ,&b ,&n );
    if (a < b )swap(a, b );
    for (int i = 1; i <= a /i ;i++)
    {
        if (a % i == 0 && b % i == 0 )v.pb(i);
        if (a % i == 0 && a/i != i && b%(a/i) == 0 )v.pb(a/i);
    }
    sort(all(v));
    while (n--)
    {
        int l , r;
        scanf ("%d%d" , &l ,&r );
        printf ("%d\n" , solve (l,r));
    }

}