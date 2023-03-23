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
int main()
{
    int n ;
    scanf ("%d" , &n );
    map <int ,int >frq ;
    int mx =0 ;
    for (int i =0 ; i < n ;i++)
    {
        int v ;
        scanf ("%d" , &v );
        frq [v]++;
        mx = max (frq[v] , mx );
    }

    if (mx <= n/2 + n%2  )
    printf ("YES\n");
    else
        printf ("NO\n");


}
