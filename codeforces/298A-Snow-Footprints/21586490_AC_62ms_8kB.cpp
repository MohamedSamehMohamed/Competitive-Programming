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
string x;
int n ;
int main()
{
int l , r ;
cin >> n >> x ;
bool R , L ;
R = L = 0 ;
for (int i =0;i < SZ(x) ;i++)
{
    if (x[i] == 'L')L = 1 ;
    else if (x[i] == 'R')R =1 ;
}
if (R && !L)
{
for (int i =0 ; i < n ;i++)if (x[i] == 'R')
{
    l = i+1 ;
    break;
}
for (int i = n-1 ; i >=0 ; i--)
{
    if (x[i] == 'R')
    {
        r = i+2 ;
        break ;
    }
}
printf ("%d %d\n" , l , r );
}else if (L && !R )
{
for (int i =0 ; i < n ;i++)if (x[i] == 'L')
{
    l = i ;
    break;
}
for (int i = n-1 ; i >=0 ; i--)
{
    if (x[i] == 'L')
    {
        r = i+1 ;
        break ;
    }
}
printf ("%d %d\n" , r , l );

}else
{
    for (int i =0 ; i < n ; i++)
    {
        if (x[i] == 'R')
        {
            l = i+1 ;
            break;
        }
    }
    for (int i = n-1 ; i >=0 ;i--)
    {
        if (x[i] == 'R')
        {
            r = i+1 ;
            break;
        }
    }
    printf ("%d %d\n" , l , r );
}

}
