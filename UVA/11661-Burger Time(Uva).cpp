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
string x ;
int n ;
void solve ()
{
    cin >> x ;

    int mxr , mxd , ans = n;
    mxr = mxd = -1 ;
    for (int i =0 ; i < n ;i++)
    {
        if (x[i] == 'R')
        {
            mxr = i ;
        }else if (x[i] == 'D')
        {
            mxd = i ;
        }else if (x[i] == 'Z')
        {
            cout <<"0\n" ; return ;
        }
        if (mxr != -1 && mxd != -1 )ans = min (ans , abs(mxr - mxd ));
    }
    cout << ans <<"\n";
}
int main()
{
    while (cin >> n && n != 0 )
    {
        solve();
    }

}
