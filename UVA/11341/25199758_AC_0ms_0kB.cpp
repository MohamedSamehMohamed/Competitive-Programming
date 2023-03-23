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
int n, m ;
int dp[10][101];
int a[10][101]; 
int solve(int i=0,int rm = m)
{
    if (rm < 0 )return -1e9; 
    if (i == n )return 0 ;
    int &ret = dp[i][rm];
    if (~ret)return ret ; 
    ret = -1e9 ;
    for (int j =0 ; j < m ;j++)
        if (a[i][j] > 4 )
            ret = max (ret , a[i][j] + solve(i+1 , rm - j-1 ));
    return ret ; 
}
int main()
{
    int t; 
    scanf("%d" , &t );
    while (t--)
    {
        scanf("%d%d" , &n ,&m);
        for (int i =0 ; i < n ;i++)
            for (int j =0 ; j < m;j++)
                scanf("%d" ,a[i] + j); 
        memset(dp , -1 ,sizeof dp);
        int ans = solve();
        if (ans <= 0 )
        printf ("Peter, you shouldn't have played billiard that much.\n");
        else
        printf ("Maximal possible average mark - %.2f.\n" , (1e-8 + ans) / n ); 
    }
}
