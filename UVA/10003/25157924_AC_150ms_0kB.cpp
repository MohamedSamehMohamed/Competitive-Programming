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
int L, n;
int a[50];
int dp[50][50];
int solve(int li =0,int ri =n-1 , int l=1 ,int r= L)
{
    if (li > ri )return 0;
    if (li == ri)return r - l + 1;  
    int &ret = dp[li][ri];
    if (~ret)return ret ; 
    ret = 1e9 ;
    for (int i= li ; i <= ri ;i++)
    {
        ret = min (ret , (r-l+1) + solve(li , i-1 , l , a[i]) + solve(i+1 , ri , a[i]+1 , r )  );
    }
    return ret ; 
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> L && L )
    {
        cin >> n;
        memset(dp , -1 ,sizeof dp);
        for (int i =0 ; i < n ;i++)
            cin >> a[i];
        cout << "The minimum cutting is " << solve() <<".\n"; 
    }
}