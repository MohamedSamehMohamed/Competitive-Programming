// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo ()
{
    fflush(stdout);
}
using namespace std ;
double dp[1001][101];
int M , W , C ;
double mp , wp ;
double solve (int tk ,  int rem )
{
    if (!rem)return tk % 2 == 0;
    double &ret = dp[tk][rem];
    if (ret == ret )return ret ;
    ret =0 ;
    return ret = mp * solve(tk + 1, rem - 1 ) + wp * solve( tk , rem - 1 );
}
int main ()
{
    while (scanf ("%d%d%d" , &M ,&W ,&C) && (M || W ))
    {
        mp = 1.0*M / (W + M );
        wp = 1.0*W / (W + M) ;
        memset (dp , -1 ,sizeof dp );
        printf ("%.9f\n" , solve(0 , C ));
    }

    return 0;
}
