// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
long long p, q;
int mx = 1e5;
long long removeP(int prime)
{
  long long cur = p;
  while(cur % q == 0)
    cur /= prime;
  return cur;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> p >> q;
    long long ans = removeP(q);
    for (int i = 2; i <= mx; i++)
    {
      if (q % i || p % i)continue;
      ans = max(ans, removeP(i));
    }
    cout << ans << '\n';
  }
}
