/*
Author : Mohamed Sameh


███▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓▓▓╬╬╬╬╬╬▓█
███▓███████▓▓╬╬╬╬╬╬╬╬╬╬╬╬▓███▓▓▓▓█▓╬╬╬▓█
███████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓█
████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬█
███▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
███▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓█
████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬█
███▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
███▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
█████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
█████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
█████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓██
█████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓██
█████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬███
██████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓███
███████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬████
███████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓████
████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█████
█████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓██████
██████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓███████
███████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓████████
██████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬██████████
███████████████▓▓▓██▓▓╬╬╬╬╬╬▓███████████
*/

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
// To not Do Cast D:
ll B , C  ,S ;
ll nb , ns ,nc ;
ll pb , ps ,pc ;
ll R ;
ll N ;
int main ()
{
    string t ;
    t = ReadStr() ;
    for (int i =0 ; i < t.size() ;i ++)
    {
        switch ( t[i] )
        {
        case 'B' :
            B++;
            break;
        case 'C':
            C++;
            break;
        case 'S':
            S++;
            break;
        }
    }
    nb = ReadInt() ;
    ns = ReadInt() ;
    nc = ReadInt() ;

    pb = ReadInt() ;
    ps = ReadInt() ;
    pc = ReadInt() ;

    R = ReadLong() ;
    ll l = 0 , r = 1e12 + 100 ;
    while (l<=r)
    {

        ll m = (l+r)>>1 ;
        ll Price = (  ( B*m - nb < 0 ? 0 :B*m - nb)*pb + ( C*m - nc < 0 ? 0 :C*m - nc)*pc + ( S*m - ns < 0 ? 0 :S*m - ns)*ps );

        if (Price <= R )
        {
            N = m;
            l  = m + 1;
        }else
        {
            r = m - 1;
        }
    }
cout << N <<"\n";
   return 0 ;
}
