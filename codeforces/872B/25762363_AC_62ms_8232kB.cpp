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
const int M  = 1e5 ;
const int Lg =  20 ;
int spt[M][Lg]; 
int Log[M+1];
int n, k;
void buildSparse()
{
    for (int i=2 ;i <= M ;i++)
    {
        Log[i] = Log[i/2] + 1;  
    }
    for (int lg = 1 ; lg < Lg ;lg++)
    {
        for (int i = 0 ; i + (1<<lg) <= n ;i++)
        {
            spt[i][lg] = min( spt[i][lg-1] , spt[ i + (1<<(lg-1)) ][lg-1] ); 
        }
    }
}
int Minquery (int l, int r)
{
    int sz = Log[r-l+1]; 
    return min ( spt[l][sz] , spt[ r - (1<<sz)+1 ][sz] );
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k ;
    int mn = 2e9 ;
    for (int i =0 ; i < n ;i++)
    {
        cin >> spt[i][0]; 
        mn = min (mn , spt[i][0] );
    }
    if (k == 2 )mn = max(mn , spt[n-1][0]); 
    for (int i =0 ; k!=1 && i + 1 < n ;i++)
    {
        if (k == 2 )
        {
            mn = max (mn ,  max(Minquery(0,i), Minquery(i+1,n-1) ) );
        }else 
        {
            if (i-1 >= 0 )
            mn = max(mn , max({spt[i][0] , Minquery(0,i-1) , Minquery(i+1 , n-1)})); 
        }
    }
    cout << mn <<"\n";
}