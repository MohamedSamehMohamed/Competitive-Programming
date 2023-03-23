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
int n,m;
const int M = 1e3 + 9 ;
ll dp[M][M];
bool bad[M][M];
bool f = 0; 
ll solve (int row =0 , int col =0 )
{
    if (row == n || col == m || bad[row][col])return 0;
    if (row == n-1 && col == m-1 )return 1 ; 
    ll &ret = dp[row][col]; 
    if (~ret)return ret ; 
    ret = solve(row + 1 , col) + solve(row , col + 1 ); 
    return ret ; 
}
void test ()
{
    memset(dp , -1 ,sizeof dp);  
    memset(bad ,0,sizeof bad);
    scanf ("%d %d" , &n ,&m);
    getchar(); 
    for (int i =0 ; i < n ;i++)
    {
        int cur, row;
        string line ;
        getline(cin, line);
        stringstream sin(line);
        sin >> row;
        row--;
        while(sin >> cur) {
                cur--;
                bad[row][cur]=1; 
        }
        
    }
    printf("%lld\n" , solve());
    
}
int main ()
{   
    int t ;
    scanf ("%d" , &t );
    while (t--)
    {
        if(f)printf("\n");
        f = 1 ;
        test();
    }
}