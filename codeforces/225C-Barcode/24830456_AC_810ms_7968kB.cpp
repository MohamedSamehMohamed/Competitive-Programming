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
const int M = 1e3 + 5 ;
int n, m, x, y ;
int W[M];
int dp[M][M][2];
// 1 black | 0 white 
int solve (int i =0 , int cnt =0 , bool last = 0 )
{
    if (cnt > y )return 1e9 ;
    if (i == m)return (cnt >= x ? 0 : 1e9 ); 
    int &ret = dp[i][cnt][last];
    if (~ret)return ret ; 
    ret = 1e9 ;
    if (last)
    {
        ret =  W[i]+ solve(i+1 , cnt + 1 , last ) ;
        if (cnt >= x )
        ret = min (ret , (n-W[i]) + solve(i+1 , 1 , 0)  );
    }else 
    {
        ret =  (n-W[i]) + solve(i+1 , cnt + 1 , last ) ;
        if (cnt >= x||!i)
        ret = min (ret , W[i] + solve(i+1 , 1 , 1)  );
        
    }
    return ret ; 

}
int main ()
{   
    memset (dp , -1  ,sizeof dp); 
    cin >> n >> m >> x >> y ;
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < m ;j++)
        {
            char c ;
            cin >> c ;
            if (c == '.')W[j]++; 
        }
    }
    cout << solve() <<"\n"; 
}

