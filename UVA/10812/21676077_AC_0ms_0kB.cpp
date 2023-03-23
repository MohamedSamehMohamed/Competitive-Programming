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
    int t ;
    scanf ("%d" , &t );
    while (t--)
    {
        int a, b ;
        scanf ("%d%d" , &a ,&b );
        int l1 , l2 ;
        l1 = l2 = -1 ;
        for (int i =0  ; i <= a ; i++)
        {
            if ( abs ( abs(a - i) - i  ) == b )
            {
                l1 = abs (a - i );
                l2 = i ;
                break;
            }
        }
        if (l1 < l2 )swap (l1 , l2 );
        if (l1 != -1 )
            printf ("%d %d\n" , l1 , l2 );
        else printf("impossible\n");
    }
}
