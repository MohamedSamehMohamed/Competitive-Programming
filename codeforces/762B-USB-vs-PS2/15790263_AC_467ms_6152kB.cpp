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
vector <ll> Usb , Ps2 ;
string Type ;
int a , b , c , m , n;
ll Cost ;
int main ()
{
a = ReadInt() ;
b = ReadInt() ;
c = ReadInt() ;
m = ReadInt() ;

for (int i =0 ; i < m ; i++)
{
    ll Num ;
    Num = ReadInt() ;
    Type = ReadStr() ;
    if (Type == "USB")
    {
        Usb.pb(Num);
    }else{

        Ps2.pb(Num);
    }
}
Usb.pb(0);
Ps2.pb(0);
sort(all(Usb));
sort(all(Ps2));
for (int i =1 ; i < Usb.size() ; i++)
    Usb[i]+=Usb[i-1];
for (int i =1 ; i < Ps2.size() ; i++)
    Ps2[i]+=Ps2[i-1];


int SU , SP;
SU =min ( (int) Usb.size() -1 , a );
SP =min ( (int) Ps2.size() -1 , b );
Cost +=Usb [ SU ] ;
Cost +=Ps2 [ SP ];

int RU = ((int)Usb.size() -1) - min ( (int) Usb.size() -1 , a ) ;
int RP = ((int)Ps2.size() -1) - min ( (int)  Ps2.size() -1 , b ) ;
n += min ( (int) Usb.size() -1 , a ) + min ( (int) Ps2.size() -1 , b );

if ( n < m ){
if ( RU + RP > c && c != 0 )
{


if (RU == 0 || RP == 0)
{

    if (RU==0)
    {
        n+= min ( RP , c ) ;
        Cost +=Ps2[SP+c] - Ps2[SP];

    }else
    {
        n+= min ( RU , c ) ;
        Cost +=Usb[SU+c] - Usb [SU];
    }
}
else {

for (int i = SU+1 , j = SP+1 ; c >0 ; )
{

    ll First , Second ;
    bool FF , SS ;
    FF = SS = 0 ;
    First = Second = 1e9 + 9 ;
    if (i < Usb.size() )
     First = Usb[ i ]-Usb [ i-1 ];
        else
            FF = 1;
        if (j < Ps2.size() )
     Second = Ps2 [j]-Ps2[j-1];
        else
            SS = 1;
    if (FF&&SS)
        break ;

    if (  i < Usb.size() && min (First , Second ) == Usb[i] - Usb[i-1] )
    {
        i++;
    }else
    {
        j++;
    }
    n++;
    c--;

    Cost +=min(First , Second );
}
}
}else if (c!=0&& RU + RP != 0 )
{

    Cost = Usb[Usb.size()-1] + Ps2[Ps2.size()-1] ;
    n+=min(RU+RP , c) ;
}
}
cout << n << " " << Cost <<"\n";
return 0 ;
}
