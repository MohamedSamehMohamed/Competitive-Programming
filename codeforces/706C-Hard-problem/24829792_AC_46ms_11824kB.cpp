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
const int M = 1e5 + 9;  
string words[M][2];
ll dp[M][2];
int cost[M];
bool ok[M][4]; 
int n ;
char arr[M];
ll MAX = 1e18 ;
/*
0-> not reversed 
1-> reversed 
ok[i][0] -> 00 
ok[i][1] -> 01
ok[i][2] -> 10
ok[i][3] -> 11    
*/
ll solve (int i =0 , bool st = 0)
{
    if (i == n - 1)
    return 0;
    ll &ret = dp[i][st]; 
    if (~ret)return ret ; 
    ret = MAX ; 
    if (st)
    {
     if (ok[i][2])
     ret = min (ret , solve(i+1,0)); 
     if (ok[i][3])
     ret = min (ret , cost[i+1] + solve(i+1,1));
    }else 
    {
        if (ok[i][0])
        ret = min (ret , solve(i+1,0));
        if (ok[i][1])
        ret = min (ret , cost[i+1] + solve(i+1,1));
    }
    return ret ; 
}
int main ()
{   
    memset(dp , -1 ,sizeof dp); 
    scanf ("%d" , &n );
    for (int i =0 ; i < n ;i++)
    scanf ("%d" , cost+i);
    for (int i =0 ; i < n ;i++)
    {
        scanf ("%s" , arr ); 
        words[i][0] = arr ;
        words[i][1] = words[i][0]; 
        reverse(all(words[i][1]));  
    }

    for (int i =0 ; i < n-1 ;i++)
    {
        int op = 0; 
        for (int k =0 ; k <= 1 ; k++)
        {
            for (int j = 0; j <= 1 ;j++)
            {
                if (words[i][k] <= words[i+1][j])
                ok[i][op]=1; 
                op++;
            }
        }

    }
    
    ll ans = min ( solve(), cost[0]+solve(0,1)); 
    if (ans >= MAX )ans = -1 ; 
    printf ("%lld\n" , ans); 
    
}

