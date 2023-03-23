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
int n , s;  
int a[100001]; 
int main ()
{
    scanf ("%d%d" , &n ,  &s );
    for (int i=0;i<n;i++)
        scanf ("%d" , a+i ); 
    int k = 0 ; 
    int mincost =1e9;
    int l = 0 , r = n , m ; 
    vector <ll> modi (n); 
    while (l<=r)
    {
        m = (l+r)>>1; 
        for (int i=0;i<n;i++)
            modi[i] = a[i] + 1LL*(i+1)*m ; 
        sort (all(modi)); 
        ll curcost =0 ;
        for (int i =0 ; i < m ; i++)
            curcost += modi[i]; 
        if (curcost <= s )
        {
            mincost = curcost ; 
            k = m ; 
            l = m+1;
        }else 
            r = m-1; 
    }
    cout << k <<" " << mincost <<"\n";
    
  return 0 ; 
}
