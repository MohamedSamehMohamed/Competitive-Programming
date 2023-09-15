// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int t;cin >> t;
  while(t--)
  {
    int n, k;cin >> n >> k;
    int cur = 0;
    string str = "abc";
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
      cout << str[idx];
      cur++;
      if (cur == k)
      {
        if (i + 1 < n)
        {
          idx++;
          idx %= 3;
          cout << str[idx];
          i++;
          idx++;
          idx %= 3;
        }
        cur = 0;
      }
    }
    cout <<"\n";
  }
}
