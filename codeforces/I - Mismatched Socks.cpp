// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int n;
int a[1009];
int main()
{
  cin >> n;
  long long ans = 0;
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    mx = max(mx, x);
    ans += x;
  }
 
  cout << min(ans/2, ans - mx) << '\n';
}
