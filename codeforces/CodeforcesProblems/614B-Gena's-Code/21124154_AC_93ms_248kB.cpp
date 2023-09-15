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
bool beaty(string x )
{
    int one =0 ;
    for (int i =0 ; i < SZ(x) ;i++)
    {
        if (x[i] != '1' && x[i] != '0')return false;
        one += (x[i] =='1');
    }
        return one <= 1  ;
}
int main ()
{
    int n ;
    cin >> n ;
    string ans = "";
    int zero =0 ;
    for (int i =0 ; i < n ;i++)
    {
        string x ;
        cin >> x ;
        if (SZ(x) == 1 && x[0] == '0')
        {
            cout <<"0\n";
            return 0 ;
        }
        if (beaty(x))zero += SZ(x) - 1 ;else
            ans = x ;
    }
    if (SZ(ans) == 0)ans="1";
    cout << ans ;
    while (zero--)cout <<0;




    return 0;
}
