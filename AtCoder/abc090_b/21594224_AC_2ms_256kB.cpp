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
bool pal (int x )
{
    int t[20];
    int id =0 ;
    while (x)
    {
        t[id++] = x %10 ;
        x/=10;
    }
    id--;
    int i =0 ;
    while (i < id )
    {
        if (t[i] != t[id])return false ;
        i++; id--;
    }
    return true ;
}
int main()
{
    int a, b ;
    scanf ("%d%d" , &a ,&b );
    int ans =0 ;
    while (a <= b )
    {
        ans += pal(a);
        a++;
    }
    printf ("%d\n" ,ans );

}
