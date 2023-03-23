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
int n ;
int a[100];
int dp[5][100];
int solve (int last = 4 , int cur =0 )
{
    if (cur == n )return 0 ;
    if (!a[cur])return dp[last][cur] = 1 + solve(0 ,  cur + 1 );
    int &ret= dp[last][cur];
    if (~ret)return ret ;
    ret = 1e9 ;
    if (a[cur] == 1 && last != 1 )
    {
        ret = min (ret , solve(1 , cur + 1 ));
    }else if (a[cur] == 2 && last != 2  )
    {
        ret = min (ret , solve(2 , cur +1 ));
    }else if (a[cur] == 3 )
    {
        if (last != 1 )
            ret = min (ret , solve(1 , cur + 1 ));
        if (last != 2 )
            ret = min (ret , solve(2 , cur + 1 ));

    }else
    {
        ret = min (ret , 1 + solve(0 , cur + 1 ));
    }
    return ret ;
}
int main()
{
cin >> n ;
for (int i =0 ;i < n ;i++)cin >> a[i] ;
memset( dp , -1 ,sizeof dp );
cout << solve () <<"\n";


}
