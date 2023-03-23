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
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
using namespace std ;
int n , d  ; 
int a[100000]; 
ll ans ;  
int main ()
{
    scanf ("%d%d" , &n ,&d ); 
    for (int i =0;i<n;i++)
    {
        scanf("%d",a+i); 
    }
    for (int i =0 ; i + 2 < n ;i++)
    {
        int l = i , r = n-1 , m , j =-1  ;
        while (l <= r )
        {
            m = (l+r)>>1; 
            if (a[m]-a[i] <= d )
            {
                j = m ; 
                l = m+1;
            }else 
                r = m-1;
        }
        if (j==-1 || j - i < 2 )continue ; 
        j -= i ; 
       ans += (1LL*j*(j-1))/2 ;
    }
    
    printf ("%lld\n" , ans );
    
    return 0;
}