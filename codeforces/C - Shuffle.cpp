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
int L, R;
int InterSect(int l, int r)
{
  if (l > r || r < l || l > r)return 0;
  if (l >= L && r <= R)return r - l +1;
  int m = (l+r)>>1;
  return InterSect(l, m) + InterSect(m+1, r);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
      int n, m, x;
      cin >> n >> x >> m;
      L = R = x;
      while(m--)
      {
        int l, r;
        cin >> l >> r;
        if (l > R || r < L)continue;
        L = min(L, l);
        R = max(R, r);
      }
      cout << R - L + 1 <<"\n";
    }
 
}
