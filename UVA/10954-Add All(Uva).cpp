// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n ;
ll ans ;
int main()
{
    while (scanf ("%d" , &n) == 1 && n)
    {
        priority_queue<ll> pq ;
        for (int i =0 ; i < n ;i++){
                int x ;
                scanf ("%d" , &x );
                pq.push(-x);
        }
        ans =0 ;
        while (SZ(pq) > 1 )
        {
            int x = -pq.top();pq.pop();
            int y = -pq.top();pq.pop();
            ans += x + y ;
            pq.push(-(x+y));
        }
        printf ("%lld\n" ,ans);

    }




}
