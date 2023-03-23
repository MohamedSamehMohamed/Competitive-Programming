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
    int t;
    scanf ("%d" , &t) ;
    while (t--)
    {
        vector <int> v ;
        while (1)
        {
            int x ;
            scanf ("%d" , &x );
            if (x == 0 )break;
            v.pb(x);
        }
        sort(rall(v));
        ll ans =0 ;
        for (int i =0 ; i <SZ(v) && ans <= 5e6 ;i++)
        {

            ans += 2 * (ll)pow (v[i] , i+1);
        }
        if (ans <= 5e6 )printf ("%lld\n" ,ans );
        else
            printf ("Too expensive\n");

    }

}
