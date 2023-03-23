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
int main ()
{
int n ;
n = ReadInt() ;
int l , r ;
l = -2* 1e9;
r = 2 * 1e9;
while (n--)
{
    string sign,ans ;
    int val ;
    cin >> sign >> val >> ans  ;
    if (  sign.size() == 2  )
    {
        if (sign[0]=='>')
        {
            if ( ans == "Y" )
            {
                l = max (l,val);
            }
            else
            {
                r = min (r,val-1);
            }
        }else
        {
            if ( ans == "Y" )
            {
                r = min (r,val);
            }
            else
            {
                l = max (l,val+1);
            }

        }
    }else
    {
        if (sign[0]=='>')
        {
            if ( ans == "Y" )
            {
                l = max (l,val+1);
            }
            else
            {
                r = min (r,val);
            }

        }else
        {
            if ( ans == "Y" )
            {
                r = min (r,val-1);
            }
            else
            {
                l = max (l,val);
            }

        }

    }


}
if (  l >= (int)-2*1e9 && l <=(int)2*1e9 && l<=r  )
    cout <<l<<"\n";
else
    cout << "Impossible\n";
return 0 ;
}



