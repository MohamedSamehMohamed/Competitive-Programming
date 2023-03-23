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
vector <P2i> T1 , T2 ,  Type1 , Type2 ;
int n , m , k , x , S ;
ll MinTime  ;
int main ()
{
n = ReadInt() ;
m = ReadInt() ;
k = ReadInt() ;

x = ReadInt() ;
S = ReadInt() ;

for (int i =0 ; i < m ;i++)
    T1.pb ( {ReadInt(),0} );
for (int i =0 ; i < m ;i++)
    T1[i].s = ReadInt() ;
for (int i =0 ; i < m ; i ++)
{
    if (T1[i].s > S )
        continue ;
    Type1.pb ( T1[i] );
}
for (int i = 0 ; i < k ; i++)
T2.pb ({0,ReadInt()});
for (int i = 0 ; i < k ; i++)
    T2[i].f = ReadInt() ;
for (int i =0 ; i < k ; i++)
{
    if ( T2[i].f > S )
        continue ;
    Type2.pb ( T2 [i] );
}
sort( all (Type1) );
MinTime = (ll)n*x;
if ((int) Type1.size())
MinTime = min (  MinTime , (ll)n*Type1[0].f);
if ( (int) Type2.size())
MinTime = min (  MinTime , (ll)x * ( n-Type2[(int)Type2.size() -1 ].s  ) );

for (int i =0 ; i < Type1.size() ; i ++)
{
    int l = 0 , r =(int) Type2.size() -1 , k = -1  ;
    while (l<=r)
    {
        int m = (l+r)>>1  ;
        if ( (ll)Type1[i].s + Type2[m].f <= S  )
        {
          k = m;
          l = m +1  ;
        }else
        r = m-1 ;
    }

    if (k!=-1)
    MinTime = min (  MinTime , (ll)Type1[i].f  * (n-Type2[k].s  ) );

}

for (int i =0 ; i < Type2.size() ; i ++)
{
    int l = 0 , r =(int) Type1.size() -1 , k = -1  ;
    while (l<=r)
    {
        int m = (l+r)>>1  ;
        if ( (ll)Type1[m].s + Type2[i].f <= S  )
        {
          k = m;
          l = m +1  ;
        }else
        r = m-1 ;
    }

    if (k!=-1)
    MinTime = min (  MinTime , (ll)Type1[k].f  * (n-Type2[i].s  ) );

}
cout << MinTime <<"\n";
return 0 ;
}
