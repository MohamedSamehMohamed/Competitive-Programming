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
const int M =1e5 ;
int idx[M];
int X[M] , Y[M];
double dist (int i )
{
    double ans = 1LL*X[i] * X[i] + 1LL*Y[i] * Y[i];
    ans = sqrt (ans);
    return ans ;
}
bool cmp (int u , int v )
{
    return dist(u) < dist(v);
}
bool fi ;
void po (int x , int y )
{
    if (x > 0 )
    {
        printf ("1 %d R\n" , x);
    }else if (x < 0 )
    {
        printf ("1 %d L\n" , -x);
    }
    if (y > 0 )
    {
        printf ("1 %d U\n" , y );
    }else if (y < 0 )
    {
        printf ("1 %d D\n", -y );
    }
    if (fi == 0 )
    {
        printf ("2\n");
        fi = 1 ;
        po(-1*x , -1*y );
    }else
    printf("3\n");
}
int main()
{
    scanf ("%d" , &n );
    for (int i =0 ; i < n ;i++)scanf ("%d%d" ,X + i , Y + i  ), idx[i] = i ;
    sort(idx , idx + n , cmp );
    int ans =0 ;
    for (int i =0 ; i < n ;i++)
    {
        ans+=2;
        if (X[i] != 0 && Y[i] != 0 )
        {
            ans+=4;
        }else ans+=2;
    }
    printf ("%d\n" ,ans );
    for (int i =0 ; i < n ;i++)
    {
        fi =  0;
        po( X[ idx[i] ] , Y[ idx[i] ] );
    }
}
