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
int t, n, x ;
char c ;
void solve()
{
    cin >> n ;
    vector<int> v[n];
    int mn = n+1 ;
    for (int i =0 ; i < n ; i++)
    {
        string str;
        str = "";
        while (SZ(str) == 0 )
        getline(cin, str);
        istringstream ss(str);
        while(ss >> x)
        {
            v[i].pb(x);
        }
        mn = min (SZ(v[i]) , mn );

    }
    vector<int> ans ;
    for (int i =0 ; i < n ; i++)
    {
        if (SZ(v[i]) == mn )
            ans.pb(i+1);
    }
    for (int i =0 ; i < SZ(ans) ;i++)
    {
        cout << ans[i];
        if (i+1 == SZ(ans))cout <<"\n";
        else
            cout <<" ";
    }

}
int main()
{
    cin >> t ;
    while (t--)
    {
        solve();
    }

}

