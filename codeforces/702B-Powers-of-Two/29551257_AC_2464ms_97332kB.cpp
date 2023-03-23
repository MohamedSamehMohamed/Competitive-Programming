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
map <int , int >frq ; 
int n ; 
int a[100000]; 
ll ans ; 
int main ()
{
    scanf ("%d" , &n ); 
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%d" , a+i ); 
        frq[a[i]]++; 
    }
    for (int i =0 ; i < n ;i++){
    for (int p = 1 ; p <= 30 ;p++)
    {
        int P = pow (2 , p ); 
        P-=a[i]; 
        if ((frq[ P ] > 0 && P != a[i]) )
        {
            ans += frq[P];  
        }else if (frq[P] > 1) 
        {
            ans += frq[P]-1; 
        }
    }
    frq[a[i]]--; 
    }
    cout << ans <<"\n"; 


    return 0 ; 
}