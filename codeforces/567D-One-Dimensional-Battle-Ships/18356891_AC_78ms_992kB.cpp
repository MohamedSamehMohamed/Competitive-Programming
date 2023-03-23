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
#include <string.h>
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
int n , k , a , M ; 
int b[200000]; 
bool vis[200000]; 
bool ok (int shots )
{
   memset (vis,0,sizeof vis); 
   for (int i=0; i < shots ;i++)
       vis[ b[i]-1 ] =1 ; 
   int ok = 0; 
   for (int i =0 ; i < n ;i++)
   {
       if (vis[i])continue ; 
       int j = 0; 
       while (i < n&&!vis[i])
       {
        j++; i++; 
        if (j == a )
            {
                ok++;
                i++; 
                j=0; 
            }
       }
   }
   return ok < k ; 
}  
int main ()
{
    scanf ("%d%d%d%d" , &n , &k , &a , &M); 
    for (int i =0 ; i < M ;i++)
        scanf ("%d" ,b+i); 
    
    int l =1 , r = M ,  m , ans =-1 ; 
    while (l <= r )
    {
        m = (l+r)>>1; 
        if (ok (m))
        {
            ans = m; 
            r = m-1 ; 
        }else 
            l = m+1; 
    }
    
    printf ("%d\n" ,ans); 
    return 0 ; 
}  