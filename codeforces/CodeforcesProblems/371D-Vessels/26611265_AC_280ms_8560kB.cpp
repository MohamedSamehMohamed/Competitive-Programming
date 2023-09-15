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
#include <sstream>
#include <string.h>

typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf ("%d" , &n ) 
#define LN(n) scanf ("%lld" , &n)
#define FOR(st,n) for (int i = st ; i < n ; i++)
using namespace std ; 
int n , q; 
ll a[200000];
ll cur [200000];
int nex[200000];
int cal (int l, int r )
{
    return a[r]- (  l >= 0 ? a[l] : 0); 
}
int main ()
{
    IN(n); 
    for (int i =0 ; i < n ;i++)
    {
        LN(a[i]);
        if (i)
            a[i] += a[i-1]; 
        nex[i] = i+1 ; 
    }
    IN(q); 
    for (int i =0  ;i  < q ;i++)
    {
        int type , x , y ; 
        IN(type);  
        IN(x); 
        x--; 
        if (type == 1 )
        {
            IN(y); 
            if (cur[x] + y <= cal (x-1 , x ))
            {
                cur[x] += y ;
                if (x-1 >=0 && cur[x] == cal(x-1,x))
                    nex[x-1] = nex[x];
                    
            }else 
            {
                stack <int> st ;
                int last = x ; 
                while (x < n && y )
                {
                if (cur[x] + y <= cal (x-1 , x ))
                {
                    cur[x] += y ;
                    if (cur[x] == cal(x-1,x))
                        last = x ; 
                    break;
                }else {
                y-=cal (x-1 , x )-cur[x];
                cur[x] = cal (x-1 , x );
                if (x-1 >= 0 )
                    st.push(x-1); 
                last = x ; 
                x = nex[x];
                }
                }
                while (!st.empty())
                {
                    nex[st.top()] = nex[last];
                    st.pop();
                }
            }
        }else 
        {
            printf ("%lld\n" , cur[x]);
        }
    }
     return 0;
}