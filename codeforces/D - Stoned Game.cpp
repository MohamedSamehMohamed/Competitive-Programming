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
  int t, n, x, sum, mx;
  cin >> t;
  while(t--)
  {
    sum = mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      sum += x;
      mx = max(mx, x);
    }
    if (2 * mx > sum)
    {
      cout <<"T\n";
    }else
    {
      if (sum % 2)cout <<"T\n";
      else cout <<"HL\n";
    }
  }
}
