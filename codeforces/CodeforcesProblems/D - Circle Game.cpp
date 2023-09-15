// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5+ 1;
int d, k;
long long limit;
string sec = "Utkarsh";
string fir = "Ashish";
long long solve(long long x)
{
  long long l = 0, r = 1e5, m, ans = 0;
  while(l <= r)
  {
    m = (l+r)>>1LL;
    long long cur = m * k;
    long long p = cur * cur;
    if (cur && p / cur != cur)
    {
      r = m-1;continue;
    }
    if (cur * cur <= limit - x * x)
      ans = m, l = m+1;
    else
      r = m-1;
  }
  return ans;
}
long long pow(long long x)
{
  return 1LL * x * x;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> d >> k;
    limit = 1LL * d * d;
    long long mx = 0;
    for (int i = 1; 1LL * i * k <= d; i++)
    {
      long long cur = 1LL * i * k;
      long long need = solve(cur);
      mx = max(mx, i + need);
    }
    if (mx % 2 == 0)
      cout << sec <<"\n";
    else
      cout << fir <<"\n";
  }
}
