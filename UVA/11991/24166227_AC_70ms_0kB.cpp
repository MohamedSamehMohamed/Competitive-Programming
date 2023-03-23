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
int n , m , k ,v ;
vector<int> vec[1000000];
int main()
{
    while (scanf("%d" , &n) == 1 )
    {
        for (int i =0; i < (int)1e6 ;i++)
            vec[i].clear();
        scanf ("%d" , &m);
        for (int i =0 ; i < n;i++)
        {
            int x ;
            scanf ("%d" , &x );
            x--;
            vec[x].pb(i+1);
        }
        while (m--)
        {
            scanf ("%d%d", &k , &v);
            k--;
            v--;
            if ( SZ(vec[v]) - 1  < k )
            {
                printf ("0\n");
            }else
            printf ("%d\n" , vec[v][k]);

        }

    }

}

