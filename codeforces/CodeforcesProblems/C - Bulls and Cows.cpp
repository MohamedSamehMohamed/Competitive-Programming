// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
string x[10], y;
int a[10], b[10], seen[10];
vector<string> out;
int n;
string ans = "Incorrect data";
void build()
{
  if (y.size() == 4)
  {
    out.push_back(y);
    return;
  }
  for (int i = 0; i < 10; i++)
  {
    if (seen[i])continue;
    seen[i] = 1;
    y += char(i + '0');
    build();
    seen[i] = 0;
    y.pop_back();
  }
}
bool can(string str)
{
  for (int i = 0; i < n; i++)
  {
    int ca = 0, cb = 0;
    for (int j = 0; j < 4; j++)
    {
      if (str[j] == x[i][j])
        ca++;
    }
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        if (j == k)
          continue;
        else if (str[j] == x[i][k])
          cb++;
    if (ca != a[i] || cb != b[i])return 0;
  }
  return 1;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> a[i] >> b[i];
  }
  build();
  for (auto i: out)
  {
    if (can(i))
    {
      if (ans == "Incorrect data")
      {
        ans = i;
      }else
      {
        ans = "Need more data";
        break;
      }
    }
  }
  cout << ans <<"\n";
 
}
