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
vector<pair<int,int>> v ;
int k ;
string x ;
vector<int> ans ;
int main()
{
    while (cin >> x )
    {
        if (x == "#")break;
        int a , b ;
        cin >> a >> b ;
        v.pb({a,b});
    }
    sort(all(v));
    cin >> k ;
    int time = 0 ;
    for (int i =0 ; i < SZ(v) ; i++)
        time = __gcd (time , v[i].s );
    int gcd = time ;
    while (SZ(ans) < k )
    {
        for (int i =0 ; i < SZ(v); i++)
        {
            if (time % v[i].s == 0 )
            {
                ans.pb(v[i].f);
            }
        }
        time+=gcd ;
    }
    for (int i =0 ; i < k ;i++)
    {
        cout << ans[i] <<"\n";
    }
}
