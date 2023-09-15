// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  long long n, k;
  long long ret = 1;
  cin >> n >> k;
  while(k)
  {
    if (k & 1)
      ret = (ret * n);
    k/=2;
    n = (n * n);
  }
  cout << ret << '\n';
}
