// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair <int,int> P2i ;
////////////////////////////////////////////////////////////////////
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
///#Read And Write  From File
/*

  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

*/
int ReadInt ()
{
    int t ;
    cin >> t ;
    return t ;
}
ll ReadLong ()
{
    ll t ;
    cin >> t ;
    return t ;
}
string ReadStr ()
{
    string t ;
    cin >> t ;
    return t ;
}
const int Max = 2e6 ;
ll CM [ Max ];
ll Sg [ Max ];
int Index [Max];
int main ()
{
    int n , k ;
    cin >> n >> k ;
    for (int i =1 ;i <= n ; i++ )
        CM [ i ] = ReadInt() ;
    for (int i =1 ; i <= n ; i ++ )
        CM [ i ] += CM [ i-1 ];
    for (int i = 0 , r = k ;  r <=n ; r ++ , i++  )
        Sg[i+1] = CM [ r ] - CM [ i ];

    for (int i = n-k+1 ; i > 0 ; --i)
    {
        if (  Sg [ i ] >= Sg[ Index [  i+1 ] ])
            Index [ i ] =  i ;
        else
            Index [ i ] = Index [ i+1 ] ;
    }

P2i ans ;
ans.f = 1 ;
ans.s = Index [ k+1] ;
ll Max_Val = Sg[ 1 ] + Sg [ Index [ k+1 ] ];
for (int a = 2 ; a+k-1 < n-k+1 ; a++)
    {
        ll Temp_Max = Sg[ a ] + Sg [ Index [k+a] ] ;
        if (Temp_Max > Max_Val )
        {
            ans.f = a ;
            ans.s = Index [k+a];
            Max_Val = Temp_Max ;
        }
    }
    cout << ans.f <<" "<<ans.s <<"\n";


return 0;
}