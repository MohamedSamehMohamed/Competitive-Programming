// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
string x , y ;
int dp[26][26];
int n ;
int cost (int i , int j )
{
    return dp[i][j];
}
int main()
{
    cin >> x >> y >> n ;
    if (SZ(x) != SZ(y))
    {
        printf ("-1\n"); return 0;
    }
    for (int i =0 ; i < 26 ; i++)for (int j =0 ; j < 26 ;j++)dp[i][j] = 1e9 ;
    for (int i =0 ; i < n ;i++)
    {
        char a , b ;
        int v ;
        scanf (" %c %c %d" , &a ,&b ,&v );
        dp[ a - 'a' ][  b - 'a' ] = min ( v , dp[ a - 'a' ][  b - 'a' ] ) ;
    }
    for (int i =0 ; i < 26 ;i++)
        for (int j =0 ; j < 26 ; j++)
            for (int k =0 ; k < 26 ; k++)
                dp[j][k] = min (dp[j][k] , dp[j][i] + dp[i][k]);
    int ans =0 ;
    /*
    for (int i =0 ; i < 26 ;i++)
        for (int j =0 ; j < 26 ;j++)
    {
        if (dp[i][j] != 1e9 )
        cout <<" From : " << char (i + 'a') <<" TO : " << char (j + 'a') << " " << dp[i][j] <<"\n";
    }
    */
    for (int i =0 ; i < SZ(x) ; i++)
    {
        if (x[i] == y[i])continue ;
        int a = cost(x[i]-'a' , y[i]-'a');
        int b = cost(y[i] - 'a' , x[i] - 'a');
        int c = 1e9 ;
        char rt = 'z';
        for (int j =0 ; j < 26 ; j++)
        {
            int cur = cost(x[i] - 'a' , j) + cost (y[i] - 'a' , j);
            if ( c > cur )
            {
                rt = char (j + 'a');
                c = cur ;
            }
        }
        int mn = min (c , min (a , b ));

        if (mn == 1e9 )
        {
            printf ("-1\n"); return 0;
        }
        if (mn == a )x[i] = y[i];
        else if (mn == c )x[i] = rt ;
        ans += min (c , min (a , b ));
    }
    cout << ans <<"\n";
    cout << x <<"\n";
}
