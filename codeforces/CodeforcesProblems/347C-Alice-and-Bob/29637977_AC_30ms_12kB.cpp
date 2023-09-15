// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n ;
int g,mx;
int main()
{
    scanf ("%d" , &n) ;
    for (int i =0 ; i < n ;i++)
    {
        int x;
        scanf ("%d" , &x );
        g = __gcd (g , x );
        mx = max (mx , x );
    }
    int p = mx / g - n ;
    if (p&1)
        printf("Alice\n");
    else
        printf ("Bob\n");

}