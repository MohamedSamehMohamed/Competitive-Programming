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
const int N = 3e5 ;
ll a[N][2], ans;
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t ;
    cin >> t;
    while (t--)
    {
      int n;
      cin >> n ;
      for (int i =0; i < n ;i++)
      {
        cin >> a[i][0] >> a[i][1] ;
      }
      ans = 0;
      ll mn = 1e18 ;
      for (int i =0; i < n ;i++)
      {
        int nxt = (i+1)%n;
        ll cost = max(0LL,a[nxt][0] - a[i][1]);
        ans += cost ;
        mn = min (mn, min(a[nxt][0],a[i][1]) );
      }
      cout << ans + mn <<"\n";
    }
}
