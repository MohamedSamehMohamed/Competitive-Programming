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
const int N = 1e5 ;
int a[N], n, x ;
ll sum ;
ll pre[N];
ll sumrange(int l, int r)
{
  return pre[r] - (l >= 0 ? pre[l] : 0);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t ;
    cin >> t ;
    while (t--)
    {
      cin >> n >> x ;
      sum =0 ;
      for (int i =0 ; i < n ;i++)
      {
        cin >> a[i];
        sum += a[i];
      }
      sort(a, a+n,[](int &x, int &y){
        return x > y ;
      });
      if (sum / n >= x)
      {
        cout << n <<"\n";
        continue;
      }
      pre[0] = a[0];
      for (int i =1 ; i < n ;i++)pre[i]=pre[i-1]+a[i];
      int ans =0 ;
      for (int i =0; i < n ;)
      {
        int l = i, r = n-1 ,m, ls =-1 ;
        while (l <= r )
        {
          m = (l+r)>>1;
          int cnt = m - i + 1;
          if (sumrange(i-1,m)/cnt >= x)
          {
            ls = m ;
            l = m+1 ;
          }else
          r = m-1 ;
        }
        if (ls == -1)break ;
        ans += ls - i + 1 ;
        i = ls+1 ;
      }
      cout << ans <<"\n";
    }
}
