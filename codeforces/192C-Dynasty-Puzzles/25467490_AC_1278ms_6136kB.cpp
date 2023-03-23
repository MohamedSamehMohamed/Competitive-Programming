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
const int N = 5e5 ;
int a[N][3];
int dp[2][26][26];
int n ;
void Clear(int id)
{
  for (int i =0 ; i < 26 ;i++)
    for (int j =0 ; j < 26 ;j++)
      dp[id][i][j] = 0;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n ;
    for (int i =0 ; i < n ;i++)
    {
      string c ;
      cin >> c;
      a[i][0] = c[0] - 'a';
      a[i][1] = c.back() - 'a';
      a[i][2] = SZ(c);
    }
    // max len of a string that start with x and end with y
    int p = 0, ans = 0  ;
    dp[p][ a[0][0] ][ a[0][1] ] = a[0][2];
    for (int i = 1; i < n ; i++)
    {
      Clear(!p);
      dp[!p][a[i][0]][a[i][1]] = a[i][2];
      for (int st = 0 ; st < 26 ; st++)
      {
        for (int en = 0 ; en < 26 ; en++)
        {
          dp[!p][st][en] = max(dp[p][st][en],dp[!p][st][en]);
          if (en == a[i][0] && dp[p][st][en])
            dp[!p][st][a[i][1]] = max(dp[p][st][en] + a[i][2], max(dp[p][st][a[i][1]],dp[!p][st][a[i][1]]));

        }
      }
      p ^= 1;
    }
    for (int i =0 ; i < 26 ;i++)ans = max (ans, dp[p][i][i]);
    cout << ans <<"\n";
}
