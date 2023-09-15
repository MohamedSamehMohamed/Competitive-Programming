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
int fun(ll n)
{
  int mn = 10;
  int mx = -1;
  while(n)
  {
    int c = n % 10;
    mn = min(mn, c);
    mx = max(mx, c);
    n/=10;
  }
  return mn * mx;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    ll a, k;
    cin >> a >> k;
    k--;
    while(k-- > 0)
    {
      ll cur = a + fun(a);
      if (cur == a)break;
      a = cur;
    }
    cout << a <<"\n";
  }
}
