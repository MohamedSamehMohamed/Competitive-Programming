// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 2e5+9;
int t, n, k, d, a[N];
bool ok(int len)
{
  map<int, int> mp;
  int cnt = 1;
  mp[a[0]]++;
  int l = 0, r = 0;
  while(l < n)
  {
    while(r+1 < n && (mp[a[r+1]] != 0  || cnt + 1 <= len ) )
    {
      r++;
      if (++mp[a[r]] == 1)cnt++;
    }
    if (r - l + 1 >= d)return 1;
    if (--mp[a[l]] == 0)cnt--;
    l++;
    while(l <= r && cnt > d)
    {
      if(--mp[a[l]] == 0)cnt--;
      l++;
    }
  }
  return 0;
}
int main()
{
  FAST
  cin >> t;
  while(t--)
  {
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 1, r = n, m, ans = n;
    while(l <= r)
    {
      m = (l+r)>>1;
      if (ok(m))
      {
        r = m-1;
        ans = m;
      }else
      l = m+1;
    }
    cout << ans <<"\n";
  }
}
