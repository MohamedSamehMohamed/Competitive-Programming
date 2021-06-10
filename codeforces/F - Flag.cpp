// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
string x[101];
int main()
{
  int n, m;
  cin >> n >> m;
 
  for (int i = 0; i < n; i++)
    cin >> x[i];
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < m; j++)
      ok&=(x[i][j] == x[i][j-1]);
    if (i)ok&=(x[i][0] != x[i-1][0]);
  }
  if (ok)
    cout <<"YES\n";
  else
    cout <<"NO\n";
}
