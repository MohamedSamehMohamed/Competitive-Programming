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
    int a, b ;
    cin >> a >> b ;
    int ans =0 ;
    while (min(a , b ) >= 1 && max (a , b ) > 1 )
    {
        ans++;
        if (a > b )swap(a,b);
        a++;
        b-=2;
    }
    printf ("%d\n" ,ans );
}
