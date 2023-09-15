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
#include <cstring>
#include <iomanip>    
using namespace std ;
typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI  3.141592 
#define SZ(a) (int)a.size()
void READ (string INPUT = "NO" , string OUTPUT = "NO" )
{
    if (INPUT != "NO")
    freopen(INPUT.c_str() , "r" , stdin );
    if (OUTPUT!="NO")
    freopen ( OUTPUT.c_str() , "w" , stdout);
} 
string s ; 
int B , S , C ;
int ab , as , ac ; 
int cb , cs , cc ;  
ll R ; 
int main ()
{
    cin >> s >> ab >> as >> ac >> cb >> cs >> cc >>  R  ;
    for (int i =0 ; i < SZ(s) ;i++)
        B+=s[i]=='B' , S+=s[i]=='S' , C+=s[i]=='C'; 
    ll l = 0 , r = 1e12+100 , m , ans ; 
    while (l <= r )
    {
        m = (l+r)>>1LL; 
        ll bp = max ( 1LL*( m*B-ab )*cb , 0LL ) ; 
        ll bs = max ( 1LL*( m*S-as )*cs , 0LL ) ; 
        ll bc = max ( 1LL*( m*C-ac )*cc , 0LL ) ;
        if (bp+bs+bc <= R )
        {
            ans = m ; 
            l = m+1; 
        }else 
            r = m-1; 
        
    }
    printf ("%lld\n" , ans ); 
  
    return 0 ; 
}