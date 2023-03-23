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
const int Lg = 20 ; 
int n;
int a[M];
ll dp[M]; 
ll spt[M][Lg]; 
int LOG[M+1];
int mxIdx (int l , int lgl , int r , int lgr )
{
    int leftseg  = spt[l][lgl] ;
    int rightseg = spt[r][lgr]; 
    int suml = a[leftseg]; 
    int sumr = a[rightseg]; 
    int best = (suml > sumr ? leftseg : rightseg );
    best = (suml == sumr ? max(leftseg   , rightseg) : best );  
    return best ;         
} 
void BuildSparse()
{
    LOG[1] = 0 ; 
    for (int i = 2 ; i <= M ;i++)
    {
        LOG[i] = LOG[i/2] + 1 ; 
    }
    for (int j = 1; j < Lg ; j++)
    {
        for (int i =0 ; i + (1<<j) <= n ;i++)
        {
            spt[i][j] = mxIdx( i , j-1 , i + (1<<(j-1)) , j-1 );
        }
    }
}
int query (int l, int r )
{
    int sz = LOG[r - l + 1 ];
    return mxIdx(l , sz ,r - (1<<sz)+1 , sz ); 
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i =0 ;i < n - 1  ;i++)
    {
        cin >> a[i];
        a[i]--; 
        spt[i][0] = i;
    }
    a[n-1] = spt[n-1][0] = n-1 ;
    BuildSparse(); 
    ll ans= 0 ; 
    for (int i= n-2 ;i >= 0 ;i--)
    {
        int best = query(i+1 , a[i]);
        dp[i] = dp[best] - (a[i] - best) + n - i - 1 ; 
        ans += dp[i]; 
    }
    cout << ans <<"\n"; 
}