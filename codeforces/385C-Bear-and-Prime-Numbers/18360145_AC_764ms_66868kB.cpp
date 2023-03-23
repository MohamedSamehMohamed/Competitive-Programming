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
bool siev[10000001]; 
vector <int> p ; 
int a[1000001]; 
ll pre[1000001]; 
int mp[10000001]; 
void Si ()
{
    for (int i = 2; i * i <= 10000001 ;i++)
    {
        if (!siev[i])
        {
            for (int j = i*2 ;j< 10000001 ;j+=i)
                siev[j] =1 ; 
        }
    }
    for (int i = 2 ; i < 10000001 ;i++)
        if (!siev[i])
            p.pb(i); 

    
}
int main ()
{
    Si(); 
    int n ,q  ; 
    scanf ("%d" , &n); 
    for (int i =0 ; i < n;i++)
        scanf ("%d" , a+i ),mp[a[i]]++;
    
    for (int i =0 ; i < SZ(p) ;i++)
    {
        ll cur = p[i]; 
        while (cur <= 1e7 )
        {
            pre[i]+= mp[cur]; 
            cur += p[i]; 
        }
        if (i)pre[i]+=pre[i-1];
    }
    scanf ("%d" ,&q ); 
    while (q--)
    {
        int L , R ; 
        scanf ("%d%d" , &L , &R ); 
        int l =0  , r = SZ(p)-1 , m;
        int Lp = -1 , Rp = -1 ; 
        while (l <= r )
        {
            m = (l+r)>>1; 
            if (p[m] >= L)
            {
                Lp = m ; 
                r = m-1; 
            }else 
                l = m+1; 
        }
        l = 0 , r = SZ(p)-1; 
        while (l <= r )
        {
            m = (l+r)>>1; 
            if (p[m] <= R)
            {
                Rp = m ; 
                l = m+1; 
            }else 
                r = m-1; 
        }
        if (Rp == -1 || Lp == -1 )
        {
            cout <<"0\n"; 
            continue ;
        }
        ll ans =pre[Rp] - (Lp-1 < 0 ? 0 : pre[Lp-1]); 
        printf ("%lld\n" , ans ); 
    }
    return 0 ; 
}  
