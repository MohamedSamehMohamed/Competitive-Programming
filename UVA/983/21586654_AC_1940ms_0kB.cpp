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
int n , m ;
int a[1002][1002];
int out[1002][1002];
int main()
{
    bool f =0 ;
    while (~scanf ("%d%d" , &n ,&m))
    {
        if (f)printf ("\n");
        for(int i = n-1 ; ~i ; i--)
        {
            for (int j =0 ; j < n ;j++)
                scanf ("%d" , &a[i][j]);
        }
        int tot =0 ;
        int mxr , mxc ;
        mxr = mxc = 0;
        for (int i =0 ; i + m <= n ;i++)
        {
            for (int j =0 ; j+m <= n ;j++)
            {
                int sum =0 ;
                for (int i1 = i ; i1 - i < m ; i1++)
                {
                    for (int j1 = j ; j1 - j < m ;j1++ )
                    {
                        sum += a[i1][j1];
                    }
                }
                mxr = i ;
                mxc = max (mxc , j );
                out[i][j] = sum ;
                tot+=sum;
            }
        }
        for (int i =mxr ; ~i ; i--)
            for (int j =0 ; j <= mxc ;j++)
            {
                cout << out[i][j] <<"\n";
            }
        cout << tot <<"\n";
        f = 1;
    }

}
