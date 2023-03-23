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
int n, d ;
const int M = 30001;
int has[M];
int dp[M][300][2]; 
int solve(int i=d , int last = d )
{
    if (i >= M )return 0;
    int dif = abs (d- last); 
    int p = (d > last); 
    int &ret = dp[i][dif][p];
    if (~ret)return ret ; 
    ret = has[i] + max ( solve(i+last , last) , solve(i+last + 1 , last + 1 ));
    if (last != 1 )ret = max (ret , has[i] + solve(i+last - 1 , last -1 )); 
    return ret ; 

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d ;
    for (int i =0 ; i < n ;i++)
    {
        int x;
        cin >> x ;
        has[x]++;
    }
    memset(dp ,-1 ,sizeof dp);
    cout << solve() <<"\n";
}
