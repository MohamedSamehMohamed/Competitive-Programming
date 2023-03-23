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
const int M = 100 ;
int a[M][M];
int dp[M];
int tem[M];
int ans = -2 * M  ;
int n ; 
void Fun(int col )
{
    for (int i =0 ; i < n ;i++)
        tem[i] += a[i][col]; 
    int cur ;
    dp[0] = cur = tem[0];
    for (int i= 1; i < n;i++)
    {
        dp[i] = max (dp[i-1] + tem[i] , tem[i]); 
        cur = max (cur , dp[i]);
    }
    ans = max (cur , ans );
} 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n ;
    for (int i =0 ; i < n ;i++)
        for (int j =0 ; j < n ;j++)
            cin >> a[i][j]; 
    for (int l =0 ; l < n;l++)
    {
        memset(tem , 0 , sizeof tem);
        int r = l;
        while (r < n )
        {
            Fun(r);
            r++;
        }
    }
    cout << ans <<"\n"; 
}
