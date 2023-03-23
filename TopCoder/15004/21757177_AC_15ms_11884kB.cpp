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
class  Reroll
{
public :
int dp[22][30*6];
int n ;
int tar ;
int a[30];
int solve (int id , int sum )
{
    if (id == n)
    {
        if (sum == tar )return 0;
        return 1e9 ;
    }
    int &ret = dp[id][sum];
    if (~ret)return ret ;
    ret = 1e9 ;
    ret = solve(id + 1 , sum + a[id] );
    for (int i = 1 ; i <= 6 ;i++)
    {
        if (i == a[id] )continue ;
        ret = min (ret , 1 + solve(id +1 , sum + i ));
    }
    return ret ;
}
int minimumDice(int target, vector<int> dice)
{
    tar = target ;
    n = dice.size() ;
    for (int i =0 ; i < n ;i++)a[i] = dice[i];
    memset(dp , -1 ,sizeof dp);
    return solve(0 , 0);
}
};
