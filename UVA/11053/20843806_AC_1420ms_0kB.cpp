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
    int n , a ,b ;
    while (scanf ("%d" , &n ) && n != 0)
    {
        scanf ("%d%d" , &a , &b );
        map <int ,int > mp ;
        int ans = n ;
        int M = n ;
        for (ll i =0 ; ; i = (a%M * i%M * i%M + b%M )%M )
        {
            mp[i]++;
            if (mp[i] == 2 )ans--;
            if (mp[i] == 3 )break;
        }
        printf ("%d\n" ,ans );
    }
    return 0;
}


