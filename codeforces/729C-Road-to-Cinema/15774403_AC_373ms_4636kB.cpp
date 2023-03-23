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

int MinC = 1e9+9 ;
int n , k , S , t , Maxd  ;
vector <P2i> Cars ;
vector <int> Stations , Dist   ;
int main ()
{
n = ReadInt() ;
k = ReadInt() ;
S = ReadInt() ;
t = ReadInt() ;
for (int i =0 ; i < n ; i ++)
{
    int c , v ;
    c = ReadInt() ;
    v = ReadInt() ;
    Cars.pb ( {v,c} );
}
sort (all(Cars));
Stations.pb (0) , Stations.pb(S);
for (int i =0  ; i < k ; i ++)
{
    Stations.pb (ReadInt());
}
sort (all(Stations));
for (int i =1 ; i < k+2 ; i++)
{
    Dist.pb (  Stations[i] - Stations [i-1] );
    Maxd = max (Maxd , Stations[i] - Stations[i-1] ) ;
}
sort( all(Dist) );
int L = -1 ;
int l = 0 , r = n-1 ;
while (l<=r)
{
    int m = (l+r)>>1 ;
    if (Cars[m].f >= Maxd )
    {
        L = m ;
        r = m - 1 ;
    }else
    l = m+1;
}
if (L==-1 || S > t )
{
    cout << "-1\n";
    return 0 ;
}
if (S*2<=t)
{
while (L<n)
{
    MinC = min (MinC , Cars[L++].s);
}
cout << MinC << "\n";
}else
{
 int Start = -1 ;
 int Acc = S - (t - S)  ;
 int Left = L , Right = n-1 ;
 while (Left <= Right ){
     int i = (Left + Right ) >> 1 ;
     bool ok =0 ;
     int Done = 0 ;
     for (int j = 0 ; j < Dist.size() ; j++){
     int l = 0 , r = Acc ;
        int Take = 0 ;
        while (l<=r)
        {
            int m  = (l+r) >> 1 ;
            ll Fuel = (ll)(m * 2) + (  Dist[j]-m   );

            if (Dist[j]-m < 0 )
            {
                r = m -1;
                continue ;
            }
            if ( Fuel <= Cars[i].f  )
            {
                Take=m ;
                l = m + 1 ;
            }else
            {
                r = m - 1 ;
            }
        }
        Done += Take ;
        if (Done>=Acc)
        {
           Start = i;
           Right = i - 1;
           break ;
        }
        if (Take == 0 ){Left = i + 1 ; break ;}
        if (j + 1 == Dist.size() )
        {
            Left = i + 1 ;
        }
     }
 }

 if (Start == -1 )
 {
     cout << "-1\n";
 }else
 {
    while (Start < n )
    {
        MinC = min (MinC , Cars[Start++].s );
    }
    cout << MinC <<"\n";
 }
}
   return 0 ;
}