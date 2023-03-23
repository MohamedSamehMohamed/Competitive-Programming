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
int ci[200000];
int vi[200000];
vector <int> road ; 
int n , k , s , t , a  ; 
int ans = 2e9 ; 
bool ok (int fuel )
{
    // Can this value of Fuel make The Car Reach the Target in the Time ?  
    int Time =0 ;  
    for (int i =0 ; i < SZ(road) ;i++)
    {
        if (fuel < road[i])return false;  
        int l =0 , r = road[i] , m , mx =0  ; 
        while (l <= r )
        {
            m = (l+r)>>1; 
            if (2*m > fuel ){r= m-1;continue;}
            if (fuel-2*m >= road[i]-m)
            {
                mx = m ; 
                l = m+1;
            }else 
                r = m-1; 
        }
        Time += mx + (2*(road[i]-mx)); 
    }
    return Time <= t ; 
}
int main ()
{
    scanf ("%d%d%d%d" , &n , &k,&s,&t); 
    for (int i =0 ; i < n ;i++)
        scanf ("%d%d" ,ci+i ,vi+i ); 
    for (int i =0 ; i < k ;i++)
    {
        scanf ("%d" , &a ); 
        road.pb(a); 
        
    }
    road.pb(0);
    road.pb(s);
    sort (all(road)); 
    for (int i = 1; i < SZ(road);i++)
        road[i-1] = road[i]-road[i-1]; 
    road.pop_back();
    int l =0 , r = 1e9 , m , fuelnedded = -1  ; 
    while (l <= r )
    {
        m = (l+r)>>1 ; 
        if (ok(m))
        {
            fuelnedded = m ; 
            r =m-1; 
        }else 
            l =m+1; 
    }
    for (int i =0 ; i < n ;i++)
    {
        if (vi[i] >= fuelnedded && fuelnedded !=-1  )
            ans = min (ans , ci[i]); 
    }
    if (ans == 2e9)ans =-1; 
    printf ("%d\n" , ans ); 
    return 0 ; 
}