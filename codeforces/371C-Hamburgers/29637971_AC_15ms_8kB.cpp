// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
#include<deque>
#include<iomanip>
using namespace std ;


typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI  3.141592 
#define SZ(a) (int)a.size()
string Rec ;
int nb , ns , nc ;
int pb , ps , pc ;
ll R  ;
ll MaxH ;
int Nb , Ns , Nc ;

int main (){
cin >> Rec >> nb >> ns >> nc >> pb >> ps >> pc >> R ; 
for (int i =0 ; i < Rec.size() ; i++)
{
    switch ( Rec[i] )
    {
    case 'B':
        Nb++;
        break;
    case 'S':
        Ns++;
        break;
    case 'C':
        Nc++;
        break;
    }
}


ll l = 0 , r = 1e12 + 101  ;
while (l<=r)
{
    ll m = (l+r) / 2;

    ll a = (ll)( ( m*Nc - nc <  0 ? 0 : m*Nc - nc ) )*pc;
    ll b = (ll)( ( m*Nb - nb <  0 ? 0 : m*Nb - nb ) )*pb;
    ll c = (ll)( ( m*Ns - ns <  0 ? 0 : m*Ns - ns ) )*ps;


    ll Tem = a  + b  +  c ;
    if (Tem == R )
    {
        MaxH = m ;
        break ;
    }
    else if (Tem < R )
    {
        MaxH = m;
        l = m + 1 ;
    }
    else
    r = m-1 ;
}



cout << MaxH <<"\n";


return 0;}