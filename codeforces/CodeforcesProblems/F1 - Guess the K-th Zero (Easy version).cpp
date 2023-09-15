#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n, t, k;
  cin >> n >> t >> k;
  int l = 1, r = n, m, ans = -1;
  while(l <= r)
  {
    m = (l+r) >> 1;
    cout << "? " << 1 << " " << m << endl;
    int answer;cin >> answer;
 
    if (m-answer >= k)
      ans = m, r = m-1;
    else
      l = m + 1;
  }
  cout << "! " << ans << endl;
 
}
