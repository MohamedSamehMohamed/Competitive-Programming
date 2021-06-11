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
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, x;
    cin >> n >> x;
    bool ok = 0;
    int mx =0;
    for (int i = 0; i < n; i++)
    {
      int tm;cin >> tm;
      if (tm == x)ok=1;
      mx = max(mx, tm);
    }
    if (ok)cout << "1\n";
    else
      cout << max(2, (x+mx-1)/mx) <<"\n";
  }
}
