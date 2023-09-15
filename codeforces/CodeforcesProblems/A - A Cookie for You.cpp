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
  ll a, b, n, m;
  cin >> a >> b >> n >> m;
  while(n+m > 0)
  {
    ll cur = n+m;
    ll rm = min(n,abs(a - b));
    if (a > b)a-=rm;
    else
    b-=rm;
    n-=rm;
    rm = min(m, min(a, b));
    m-= rm;
    if (min(a, b) == a)a-=rm;
    else
    b -= rm;
    if (n + m == cur)break;
//      cout << a <<" " << b <<" " << n <<" " << m <<"\n";
  }
  if (n)
  {
    if (n <= a+b)n=0;
  }
//  cout << n <<" " << m <<"\n";
  if(n+m == 0)cout <<"Yes\n";
  else
  cout <<"No\n";
}
}
