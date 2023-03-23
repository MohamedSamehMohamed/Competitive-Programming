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
bool siev[1000000]; 
vector <ll> ans; 
int main ()
{
    for (int i = 2; i * i <= 1000000 ;i++)
        if (!siev[i])
            for (int j = i*2 ; j< 1000000 ;j+=i)
                siev[j]=1; 
    for (int i = 2;  i < 1000000 ;i++)
    {
        if (siev[i])continue ; 
        ll cur = 1LL*i*i ; 
        while (cur <= 1e12 )
            ans.pb(cur),cur*=i; 
    }
    sort (all(ans));
    int n ; cin >> n ; 
    while (n--)
    {
        ll L , R ; 
        cin >> L >> R ; 
        int l =0 , r = SZ(ans)-1,m; 
        int j , k ;
        j = k = -1; 
        while (l <= r)
        {
            m =(l+r)>>1; 
            if (ans[m] >= L)
            {
                j = m; 
                r = m-1; 
            }else 
                l = m+1;
        }
        if (j == -1)
        {
            printf ("0\n"); 
            continue ; 
        }
        l = 0 , r = SZ(ans)-1; 
        while (l <= r)
        {
            m =(l+r)>>1; 
            if (ans[m] <= R)
            {
                k = m; 
                l = m+1; 
            }else 
                r = m-1;
        }
        printf ("%d\n" , k-j+1 ); 
    }
    return 0 ; 
}  
