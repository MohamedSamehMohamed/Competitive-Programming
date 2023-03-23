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
int n , r , avg ;
int main()
{
    cin >> n >> r >> avg ;
    vector <pair<int,int>> v(n);
    ll sum =0;
    for (int i =0 ; i < n ;i++)
    {
        cin >> v[i].s >> v[i].f ;
        sum += v[i].s ;
    }
    ll rem = 1LL * avg * n ;
    rem -= sum ;
    sort(all(v)) ;
    ll ans = 0;
    for (int i =0 ; i < n && rem > 0 ;i++)
    {
        ll ret = r - v[i].s ;
        if (ret <= rem )
        {
            ans += 1LL * ret * v[i].f ;
            rem -= ret ;
        }else
        {
            ans += 1LL * rem * v[i].f ;
            rem =0 ;
        }
    }
    cout << ans <<"\n";



}
