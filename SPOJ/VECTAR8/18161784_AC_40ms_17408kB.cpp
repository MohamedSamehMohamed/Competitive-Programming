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
bool siev [1000001];
int t , n ; 
vector <int> FearPrimes ; 
bool ZERO (int x )
{
    while (x)
    {
        if (x%10==0)return true ; 
        x/=10; 
    }
    return false  ; 
}
bool IsFear (int x )
{
    if (ZERO(x))return false;  
    int p = log10 (x);
    if (p==0)return !p ;
    p = pow (10,p);
    while (x)
    {
        if (siev[x])return false ; 
        x-=p * (x/p);
        p/=10;
    }
    return true ;
}

int main ()
{
   siev[0] = siev[1] = 1 ; 
   for (int i = 2; i * i <= 1000001 ;i++)
   {
       if (!siev[i])
       {
           for (int j = i*2 ; j < 1000001 ;j+=i )
               siev[j] =1 ; 
       }
   }
   for (int i = 2; i < 1000001 ;i++)
   {
       if (!siev[i] && IsFear(i))
           FearPrimes.pb(i); 
   }
   scanf ("%d" , &t ); 
   while (t--)
   {
       scanf ("%d" , &n ); 
       int l = 0 , r =SZ(FearPrimes)-1 , m , j=0;
       while (l<=r)
       {
           m =(l+r)>>1; 
           if (FearPrimes[m] <= n )
           {
               j= m+1 ; 
               l = m+1;
           }else 
               r = m-1; 
       }
       printf ("%d\n" , j ); 
   }
   return 0 ; 
}
