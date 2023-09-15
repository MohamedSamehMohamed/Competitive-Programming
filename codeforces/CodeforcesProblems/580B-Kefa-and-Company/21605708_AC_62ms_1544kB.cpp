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
int n, d ;
vector<pair<int,int>> v;
ll ans ;
int main()
{
    scanf ("%d%d", &n,&d );
    for (int i =0 ; i < n ; i++)
    {
        int u, v1 ;
        scanf ("%d%d",&u, &v1 );
        v.pb({u,v1});
    }
    sort(all(v));
    ll cur =0 ;
    for (int i =0, j = 0 ; j < n ;)
    {
        cur += v[j].s ;
        while (v[j].f - v[i].f >= d)
        {
            cur -= v[i].s ;
            i++;
        }
        ans = max (ans, cur );
        j++;
    }
    printf ("%lld\n",ans );
}
