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
int c, n1 ,n2 ,n3 ;
int dp[151][501][101][51];
int solve (int rem = c , int a= n1 , int b = n2 , int c = n3 )
{
    if (rem < 0 || a < 0 || b < 0 || c < 0 )return 1e8 ;
    if (rem == 0 )return 0;
    int &ret = dp[rem][a][b][c];
    if (~ret)return ret;
    /*
    8 -> 11111111
    8 -> 1115

    */
   ret = 1e9 ;
   for (int ones = 0 ; ones <= 8;ones++)
   {
       for (int fives = 0 ; fives <= 2 ;fives++)
       {
           for (int tens = 0 ; tens <= 1 ; tens++)
           {
               int cur = ones + fives*5 + tens * 10 ;
               if (cur < 8)continue ;
               int rm = cur - 8 ;
               ret = min (ret , ones + fives + tens +  solve(rem-1 , a - ones + (rm%10)%5  , b - fives + (rm%10)/5 , c - tens + rm / 10   )    );
           }
       }
   }
   return ret ;

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp , -1 ,sizeof dp);
    int t ;
    cin >> t ;
    while (t--)
    {
        cin >> c >> n1 >> n2 >> n3 ;
        cout << solve() <<"\n";
    }

}
