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
string x ;
string con (int y )
{
    string rt ="";
    while (y)
    {
        rt += char(y%10 + '0');
        y/=10;
    }
     reverse(all(rt)) ;
    return rt ;
}
bool ok (string sub )
{
    int j =0 ;
    for (int i =0 ; j < SZ(sub) && i < SZ(x) ;i++)
    {
        if (x[i] == sub[j])j++;
    }
    return j == SZ(sub);
}
int main()
{
    cin >> x ;
    vector <string> div ;
    for (int i = 1; i <= 999 ;i++)
    {
        if (i % 8 ==0 )
        {
            div.pb(con(i));

        }
    }
    div.pb("0");
    for (int i =0 ; i <SZ(div) ;i++)
    {
        if (ok(div[i]))
        {
            cout <<"YES\n";
            cout << div[i] <<"\n";
            return 0 ;
        }
    }
    cout << "NO\n";



}