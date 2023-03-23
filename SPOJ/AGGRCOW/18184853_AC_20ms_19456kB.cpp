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
int t , n , c ;
int a[1000000]; 
bool ok (int d )
{
    int last = a[0];
    int left = c-1; 
    for (int i =1 ; left && i < n ;i++)
    {
        if (a[i]-last >= d)
        {
            last =a[i]; 
            left--; 
        }
    }
    return left == 0 ;
}
int main ()
{
    scanf ("%d" , &t );
    while (t--)
    {
        scanf ("%d%d" , &n , &c ); 
        for (int i =0 ; i < n;i++)
            scanf ("%d" , a+i ); 
        sort (a,a+n); 
        int l = 1 , r =1e9 , m , ans = 0 ; 
        while (l <= r )
        {
            m = (l+r)>>1; 
            if (ok (m))
            {
                ans = m; 
                l =m+1; 
            }else 
                r = m-1; 
        }
        printf ("%d\n" , ans ); 
    }
  
    return 0 ; 
}