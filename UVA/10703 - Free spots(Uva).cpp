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
int h ,w , n ;
int g[501][501];
void solve()
{
    memset(g , 0 ,sizeof g );
    for (int i= 0 ; i < n ;i++)
    {
        int x1 , x2 , y1 , y2 ;
        scanf ("%d%d%d%d" , &x1 , &y1 , &x2 , &y2 );
        x1--;y1--;x2--;y2--;
        if (y1 > y2 )
        {
            swap(y1 , y2 );
        }
        if (x1 > x2 )
        {
            swap(x1 , x2 );
        }
        x2++;
        for (int j = y1 ; j <= y2 ; j++)
        {
            g[j][x1]++;
            g[j][x2]--;
        }
    }
    for (int i =0 ; i < h ;i++)
        for (int j =1 ; j < w ;j++)
            g[i][j] += g[i][j-1];
    int ans =0 ;
    for (int i =0 ; i < h ;i++)
        for (int j =0 ; j < w ;j++)
            ans += (g[i][j] == 0 );
    if (ans == 0 )
    {
        printf ("There is no empty spots.\n");
    }else if (ans == 1 )
    {
        printf ("There is one empty spot.\n");
    }else
    {
        printf ("There are %d empty spots.\n" ,ans );
    }
}
int main()
{
    while (scanf ("%d%d%d" , &w , &h , &n ) == 3 )
    {
        if (  !(w || h || n ) )break;
        solve();
    }
}
