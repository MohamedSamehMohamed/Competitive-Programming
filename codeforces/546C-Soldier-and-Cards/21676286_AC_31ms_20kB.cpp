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
int n ;
queue <int> a ,b ;
int main()
{
    scanf ("%d" , &n );
    scanf ("%d" , &n );
    while (n--)
    {
        int x;
        scanf ("%d" , &x );
        a.push(x);
    }
    scanf ("%d" , &n );
    while (n--)
    {
        int x ;
        scanf ("%d" , &x );
        b.push(x);
    }
    int g = 0;
    while (g < 1000000 && !a.empty() && !b.empty() )
    {
        g++;
        int x , y ;
        x = a.front() ;a.pop();
        y = b.front() ;b.pop();
        if (x > y )
        {
          a.push(y);
          a.push(x);
        }else
        {
         b.push(x);
         b.push(y);
        }
    }
    if (a.empty())
    {
        printf ("%d %d" , g , 2 );
    }else if (b.empty())
    {
        printf ("%d %d" , g , 1 );
    }else
    {
        printf ("-1\n");
    }
}
