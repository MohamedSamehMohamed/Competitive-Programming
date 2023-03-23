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
int n , l , r , x ;
int a[15];
ll ans ;
void rec (int tk = 0 , int cur =0 , int tot = 0 , int mx = -1 , int mn = 1e9  )
{
    if (cur == n )
    {
        if (tk < 2 || tot < l || tot > r || (mx - mn < x ))return ;
        ans++;
        return ;
    }
    rec (tk , cur + 1 , tot , mx , mn );
    rec (tk + 1, cur + 1, tot + a[cur ] , max (mx , a[cur]) , min (mn , a[cur]));
}
int main ()
{
    cin >> n >> l >> r >> x;
    for (int i =0 ; i < n ;i++)cin >> a[i];
    sort(a ,a +n );
    rec ();
    cout << ans <<"\n";

     return 0;
}
