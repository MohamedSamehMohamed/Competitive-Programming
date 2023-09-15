
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

inline int ReadInt ()
{
    int t ;
    scanf ("%d" , &t) ;
    return t ;
}
inline ll ReadLong ()
{
    //return 1 +  rand()%1000000000000000000 ;
    ll t ;
    cin >> t ;
    return t ;
}


vector <ll> NLuky;
bool Count4_7(ll N )
{
    int a =0 , b = 0 ;
    while (N)
    {
        if (N%10 == 4 )
            a++;
        else
            b++;
        N/=10;
    }
    return (a == b );
}
void Generate (int n , ll Number  )
{
    if ( (ll) (log10(Number)) + 1 > n )
        return ;
    if (Count4_7( Number ))
        NLuky.pb(Number);

    Generate( n , (Number*10)+4 );
    Generate( n , (Number*10)+7 );

}
int main ()
{
   ll Number ;
   int Start = 0 ;
   Number = ReadLong() ;
   Generate( 11 , 0  );
   sort( all(NLuky));

   int l =0  , r = NLuky.size() - 1 ;
   while (l<=r)
   {
       int Mid = (l+r)/2 ;
       if (NLuky[Mid] == Number )
       {
           Start = Mid ;
           break ;
       }else if (NLuky[Mid] <  Number)
        l = Mid + 1 ;
        else
        {
            Start = Mid ;
            r = Mid - 1;
        }
   }
   cout << NLuky[Start]<<"\n";
   return 0 ;
}