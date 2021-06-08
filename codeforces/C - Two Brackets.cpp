// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int t;cin >> t;
  while(t--)
  {
    string x;cin >> x;
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    int ans = 0;
    for (int i = 0; i < x.size(); i++)
    {
      if (x[i] == '(')
      cnt[0]++;
      else if (x[i] == '[')
      cnt[1]++;
      else
      {
        if (x[i] == ')' && cnt[0])
        {
          cnt[0]--;ans++;
        }else if (x[i] == ']' && cnt[1])
        {
          cnt[1]--;ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
