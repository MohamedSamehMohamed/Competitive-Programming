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
int n, s, k;
string color;
int a[50];
const int MAX = 1e9 ;
int ans = MAX ;
int dp[51][2001];
int START = 50;
int solve (int last = START, int rem = k)
{
    if (rem <= 0)return 0;
    int &ret = dp[last][rem];
    if (~ret)return ret ;
    ret = MAX ;
    for (int i =0; i < n ;i++)
    {
        if (last == START)
        {
          ret = min(ret, abs(s - i) + solve(i, rem - a[i]));
        }else
        {
        if (i == last || a[i] <= a[last] || color[i] == color[last])continue ;
        ret = min ( ret , abs(last - i ) + solve(i , rem - a[i])  );
        }
    }
    return ret ;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s >> k ;
    s--;
    for (int i =0 ; i < n;i++)cin >> a[i];
    cin >> color ;
    memset(dp , -1 ,sizeof dp);
    ans = solve();
    if (ans == MAX )ans = -1 ;
    cout << ans <<"\n";
}
