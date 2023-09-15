// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int frq[101], a[101], n;
string build(int once)
{
  string ans = string(n, 'A');
  once/=2;
  for (int i = 0; i < n && once; i++)
  {
    if (frq[a[i]] == 1)
    {
      ans[i] = 'B';
      once--;
    }
  }
  return ans;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a+i);
    frq[a[i]]++;
  }
  int once = 0;
  for (int i = 0; i < 101; i++)
    if (frq[i] == 1)
      once++;
  if (!once)
  {
    cout <<"YES\n" << string(n, 'A') <<"\n";
    return 0;
  }
  if (once % 2 == 0)
  {
    cout << "YES\n" << build(once) <<"\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    if (frq[a[i]] > 2)
    {
      string cur = build(once);
      cur[i] = 'B';
      cout <<"YES\n" << cur <<"\n";
      return 0;
    }
  }
  cout <<"NO\n";
}
