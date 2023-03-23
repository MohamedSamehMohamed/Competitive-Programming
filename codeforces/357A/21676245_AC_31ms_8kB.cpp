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
int a[100];
int main()
{
    int n ;
    scanf ("%d" , &n );
    int x , y;
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%d" , a+i );
    }
    scanf ("%d%d" ,&x ,&y );
    for (int i = 1; i <= n ;i++)
    {
        int A , B ;
        A = B = 0 ;
        for (int j = 0 ; j < n ;j++)
        {
            if (j+1 < i )A+=a[j];
            else
                B+=a[j];
        }
        if (min(A , B ) >= x && max (A , B ) <= y )
        {
            printf ("%d\n" , i );
            return 0;
        }
    }
    printf ("0\n");

}
