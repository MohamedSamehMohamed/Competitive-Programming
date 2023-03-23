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
int n , m ;
vector<pair<int,int>> a;
ll ans =0 ;
bool cmp (pair<int,int> A , pair<int,int> B)
{
    if (A.s != B.s )return A.s > B.s ;
    return A.f > B.f ;
}
int main ()
{
    cin >> n >> m ;
    for (int i =0 ; i < m ;i++)
    {
        int u , v;
        cin >> u >> v ;
        a.pb({u,v});
    }
    sort(all(a) , cmp );
    for (int i =0 ; i < m ;i++)
    {
        if (n >= a[i].f )
        {
            n-=a[i].f ;
            ans += a[i].f * a[i].s ;
        }else
        {
            ans += n * a[i].s ;
            break;
        }
    }
    cout << ans <<"\n";
     return 0;
}
