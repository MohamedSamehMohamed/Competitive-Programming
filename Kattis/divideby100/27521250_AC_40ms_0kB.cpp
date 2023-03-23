// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Flush fflush(stdout);
using namespace std ;
int main()
{
  // freopen("", "r", stdin);
  string x, y;
  cin >> x >> y;
  int n = SZ(x);
  int m = SZ(y);
  if (m == 1)
  {
    cout << x <<"\n";
    return 0;
  }
  if (m == n+1)
  {
    while(SZ(x) && x.back() == '0')x.pop_back();
    if (SZ(x))
    cout << "0." << x <<"\n";
    else
    cout <<"0\n";
    return 0;
  }
  if (m > n)
  {
    cout << "0.";
    m-=n;
    while(m-- > 1)cout << "0";
    cout << x <<"\n";
    return 0;
  }
  string a, b;
  a = b = "";
  for (int i = 0; i < SZ(x); i++)
  {
    if (n - i + 1 <= m)b += x[i];
    else a += x[i];
  }
  while(SZ(b) && b.back() == '0')b.pop_back();
  if (SZ(b))
  cout << a <<"." << b <<"\n";
  else
  cout << a <<"\n";
}
