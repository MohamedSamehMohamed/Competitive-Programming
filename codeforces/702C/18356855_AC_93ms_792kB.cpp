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
int n , m ; 
int a[100000],b[100000]; 
bool ok (int r )
{
   int j =0 ; 
   for (int i =0 ;j < n && i < m;i++)
   {
       while (j < n && a[j] >= (ll)b[i]-r && a[j] <= (ll)b[i]+r )
           j++; 
   } 
   return j == n; 
}
int main ()
{
     scanf ("%d%d" , &n , &m ); 
     for (int i =0 ; i < n ;i++)
     {
         scanf ("%d" , a+i ); 
     }
     for (int i =0 ; i < m;i++)
     {
         scanf ("%d" , b+i ); 
     }
     ll l  =0 , r = 2e9 , m , ans ; 
     while (l <= r)
     {
         m = (l+r)>>1LL;
        
         if (ok (m))
         {
             ans = m; 
             r = m-1; 
         }else 
             l = m+1; 
     }
     printf ("%lld\n" , ans ); 
     
     
     return 0 ; 
}