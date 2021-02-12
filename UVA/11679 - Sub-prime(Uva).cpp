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
int n , b ;
int val[21];
void solve()
{
    for (int i =0 ; i < b ;i++)scanf ("%d" , val+i);
    for (int i =0 ; i < n ;i++)
    {
        int from , to , value ;
        scanf ("%d%d%d" , &from , &to , &value );
        val[from-1] -= value ;
        val[to-1]   += value ;
    }

    for (int i =0 ; i < b; i++)
    {
        if (val[i] < 0)
        {
            printf ("N\n");
            return ;
        }
    }
    printf ("S\n");
}
int main()
{
    while (scanf ("%d%d" , &b , &n ) == 2 )
    {
        if (  !(b || n) )break;
        solve();
    }
}
