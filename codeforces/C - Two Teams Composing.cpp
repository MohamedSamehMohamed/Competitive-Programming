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
const int M = 2e5 + 9;  
int a[M];
int frq[M]; 
int main()
{
    int t ;
    scanf("%d" , &t ); 
    while (t--)
    {
        scanf("%d" , &n) ;
        for (int i =0 ; i <= n ;i++)frq[i]=0;
        int d =0 ;
        for (int i =0 ; i < n ;i++)
        {
            scanf("%d" , a+i);
            if (++frq[ a[i] ] == 1 )d++;
        }
        int sam =0 ;
        int samn =0 ; 
        for (int i =0 ; i <= n ;i++)
        {
            sam = max (sam , frq[i]-1); 
            samn = max (samn , frq[i]); 
        }
        int ans = min (sam,d); 
        ans = max (ans , min(samn , d - 1)); 
        printf ("%d\n" , ans); 
 
 
 
    }
}
