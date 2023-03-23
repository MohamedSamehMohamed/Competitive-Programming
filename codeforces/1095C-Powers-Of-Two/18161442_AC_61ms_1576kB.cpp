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
int main ()
{
    int n , k ; 
    scanf ("%d%d" , &n , &k ); 
    priority_queue <int> ans ; 
    for (int i = 30 ; i >= 0 ;i--)
    {
        if ( (1<<i) <= n  )
        {
            n-= (1<<i); 
            ans.push((1<<i)); 
        }
    }
    while (SZ(ans)< k )
    {
        int c = ans.top(); 
        if (c == 1 )break; 
        ans.pop();
        ans.push(c/2);
        ans.push(c/2);
    }
    if (SZ(ans) == k )
    {
        printf ("YES\n"); 
        while (SZ(ans))
        {
            printf ("%d " , ans.top()); 
            ans.pop(); 
        }
    }else 
        printf ("NO\n"); 
    
   return 0 ; 
}
