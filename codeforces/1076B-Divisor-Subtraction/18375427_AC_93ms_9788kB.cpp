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
using namespace std ;


typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define PI  3.141592 
#define SZ(a) (int)a.size()
bool p[10000000]; 
void Primes ()
{
    for (int i =2 ; i  * i <= 10000000 ;i++)
    {
        if (!p[i])
        {
            for (int j = i*2 ; j < 10000000 ;j+=i )
                p[j]=1; 
        }
    }
}
bool Pri (ll x )
{
    for (ll i = 2 ; i * i <= x ; i++)
        if (x % i == 0)
            return 0;
    return x >= 2 ; 
}
ll sub (ll x )
{
    if (Pri(x))
        return 1 ; 
    
    ll ans =0 ; 
    for (int i =2 ;x != 0 && i < 10000000  ; i++)
    {
        
        if (!p[i])
        {
            if (x%i == 0 )
            {
                if (x%2 == 0 && i%2 == 0 ){
                ans+=x/i; 
                x%=i; 
                i = 1; 
                }else if (x%2 && i%2==0 ) 
                {
                ans+=x/i; 
                x%=i; 
                i = 1;
                }
                else 
                {
                    ans++;
                    x-=i; 
                    i=1; 
                    
                }
            }
        }
    }
    return ans ; 
}
int main ()
{
       Primes();
      
       ll x ; 
       cin >> x ; 
       ll ans = sub (x); 
       cout << ans <<"\n";
       
return 0;
}