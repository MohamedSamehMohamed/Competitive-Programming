// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
string gen(string x, int times)
{
  string y = "";
  while(times--)
    y += x;
  return y;
}
string ans, x, y;
void solve()
{
  ans = "-1";
    for (int j = 1; j <= 20; j++)
      for (int i = 1; i <= 20; i++)
      {
        if (i * x.size() != j * y.size())
          continue;
        if (ans != "-1" && i * x.size() > ans.size())
          continue;
        string cur = gen(x,i);
        string cur1 = gen(y, j);
        if (cur == cur1)
        {
          if (ans == "-1")
            ans = cur;
          if (cur.size() < ans.size())
            ans = cur;
        }
      }
}
int main()
{
  int t;cin >> t;
  while(t--)
  {
    cin >> x >> y;
    if (x.size() > y.size())
      swap(x, y);
    solve();
    cout << ans << "\n";
  }
}
