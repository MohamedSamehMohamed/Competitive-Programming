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
string str,t ;
int n,m;
const int M = 3000;
int dp[M][M];
char arr[M];
int main ()
{
    int it = 0;
    while(1)
    {
    it++;
    gets(arr);
    if (arr[0] == '#')break;
    str = arr ;
    gets(arr);
    t = arr ;
    n = SZ(str);
    m = SZ(t);
    memset(dp , 0 ,sizeof dp);
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < m ;j++)
        {
            if (str[i] == t[j])
            {
                if (i-1 >= 0 && j-1 >= 0)
                dp[i][j] = dp[i-1][j-1] + 1 ;
                else
                dp[i][j] = 1;
            }else
            {
                if (i - 1 >= 0 )dp[i][j] = max (dp[i][j] , dp[i-1][j]);
                if (j - 1 >= 0 )dp[i][j] = max (dp[i][j] , dp[i][j-1]);
            }
        }
    }
    printf ("Case #%d: you can visit at most %d cities.\n" , it, dp[n-1][m-1]);
    }

}
