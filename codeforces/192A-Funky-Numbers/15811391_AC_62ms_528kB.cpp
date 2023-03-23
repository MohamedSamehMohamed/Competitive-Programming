// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
////////////////////////////////////////////////////////////////////
#define pf push_front
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define M_P make_pair
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int main ()
{
int n ;
bool ok = 0 ;
vector < int >Numbers  ;
cin >> n ;
for (int i = 1 ; i + 1 <= n ; i++)
{
    int Num =  i * (i+1);
    if (Num %2 != 0 )
    continue ;
    Num/=2 ;
    if (Num>n)break ;
    Numbers.pb (Num);

}
for (int i = 0 ; i < Numbers.size() ; i++)
{

    int l , r , m  ;
    l = 0 ;
    r = Numbers.size() - 1 ;
    while (l<=r)
    {
        m = (l+r) /2 ;
        if (Numbers[i] + Numbers[m] == n  )
        {
            cout << "YES\n";
            ok = 1 ;
            break ;
        }
        else if (Numbers[i] + Numbers[m] < n)
            l =m+1 ;
        else
            r = m-1 ;
    }
    if (ok) break ;
}

if (!ok)cout << "NO\n";
    return 0 ;
}