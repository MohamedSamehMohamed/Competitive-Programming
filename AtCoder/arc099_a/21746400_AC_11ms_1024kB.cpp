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
int n , k ;
const int M = 1e5 + 9 ;
int a[M];
int dp[M];
int main ()
{
    scanf ("%d%d" , &n ,&k);
    for (int i=0 ; i < n ;i++)
        scanf ("%d" ,a+i );
    int st = 1 ;
    for (int i = 1; i <= k ;i++)
        dp[i] = 1;
    for (int i =0 , j = k-1 ; j < n ; st++)
    {
        dp[  j+1 ] = st ;

        i = j ;
        j = i+k-1;
    }
    for (int i = n ; i > k ;i--)
    {
        if (dp[i] == 0 )dp[i] = dp[i+1];
    }
    int ans =0 ;
            for (int i =0 , j = k - 1 ; j < n ; )
            {
                //cout << i + 1<<" " << j + 1 <<"\n";
                ans++;
                if (j == n-1 )break;
                i = j;
                j = i+k-1;
                if (j >= n )
                {
                    ans++;
                    break ;
                }
            }
    dp[n] = ans ;
    //for (int i = 1; i <=n ; i++)
     //   cout << dp[i] <<" ";
   // cout <<"\n";
    if (n == k )
    {
        printf ("1\n");
    }else
    {
        int id = 0 ;
        for (int i =0 ; i < n ;i++)if (a[i] == 1 )id = i ;
        int ans = n + 20;
        for (int i =0 ; i + k <= n ;i++)
        {
            if (id >= i && id <= i+k-1 ){
            //cout <<"Cost Left " << dp[i + (i != 0 )] <<" " << "cost Right " << dp[ n - (i+k)+1  ]<<"\n";
            //cout << i <<" " << n-(i+k)+1 <<" " << 1 + (i != n-1 ) * dp[i + (i!=0)] + dp[n - (i+k)+1] <<"\n";
           // cout <<"id "  << i+1 <<" " << i+k <<"\n";
            ans = min (ans , 1 + dp[i+ (i!=0)] + (i+k-1 != n-1)*dp[n-(i+k)+1]);
            }
        }
        cout << ans <<"\n";
    }

}
