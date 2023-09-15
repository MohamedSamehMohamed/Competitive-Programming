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
const int N = 2e5 ;
int pre[N];
int a[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t, n, k ;
    cin >> t ;
    while (t--)
    {
      cin >> n >> k;
      for (int i =0; i < n ;i++)
      {
        cin >> a[i];
        pre[i]=0;
      }
      for (int i = 1;  i < n-1 ;i++)
      {
        if (a[i] > a[i-1] && a[i] > a[i+1])pre[i]++;
        pre[i]+=pre[i-1];
      }
      int ans = 0;
      int L   = 0;
      for (int i=0 ; i+k <= n;i++)
      {
        int l = i ;
        int r = i+k-2 ;
        if (pre[r] - pre[l] > ans )
        {
          ans = pre[r] - pre[l];
          L = i ;
        }
      }
      cout << ans + 1 <<" " << L + 1 <<"\n";
    }
}
