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
int n , m , k ;
int arr[1000];
int main()
{
    scanf ("%d%d%d" , &n ,&m ,&k);
    for (int i =0 ; i < m ;i++)arr[i] = 1e9 ;
    for (int i =0 ; i < n ;i++)
    {
        int r , c ;
        scanf ("%d%d" , &r ,&c );
        r--;
        arr[r] = min (arr[r] , c );
    }
    ll ans =0 ;
    for (int i =0 ; i < m ;i++)ans += arr[i];
    ans = min (1LL*k , ans );
    printf ("%lld\n", ans );
}
