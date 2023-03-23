// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair <int,int> P2i ;

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

inline int ReadInt ()
{
    int t ;
    scanf ("%d" , &t) ;
    return t ;
}
inline ll ReadLong ()
{
 //   return 1 +  rand()%999999 ;
    ll t ;
    cin >> t ;
    return t ;
}
inline P2i ReadPair()
{
    P2i t ;
    t.f = ReadInt() ;
    t.s = ReadInt() ;
    return t ;
}
inline string ReadStr ()
{
    string t ;
    cin >> t ;
    return t ;

}
inline void ReadInt3 (int &a , int &b , int &c )
{

    scanf ("%d" , &a) ;
    scanf ("%d" , &b) ;
    scanf ("%d" , &c) ;

}
ll n , M , ans ,  Tem;
int l , r , m;
vector <ll> Pre ;
int main ()
{
n = ReadLong() ;
M = ReadLong() ;
Pre.pb (0);
for (int i =0 ; i < n ; i++)
{
    Pre.pb (ReadLong());
}
for (int i = 1 ; i <= n ; i++)
    Pre [ i ]+= Pre[i-1] ;



for (int i = 0 ; i < n ;i++ )
{
 l = i+1 , r = n   ;
 while (l<=r)
 {
    m = (l+r)>>1;
    Tem = Pre [ m ] - Pre [i];

    if (Tem <= M )
        ans = max (ans , Tem ),l=m+1;
    else
        r = m-1 ;


 }
}
cout << ans <<"\n";

return 0 ;
}
