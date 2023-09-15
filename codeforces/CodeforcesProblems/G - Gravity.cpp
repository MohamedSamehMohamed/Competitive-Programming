// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int n, m;
string x[100];
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < m; i++)
  {
    for (int j = n-1; j >= 0; j--)
    {
      if (x[j][i] != 'o')continue;
      int k = j+1;
      while(k < n && x[k][i] == '.')
      {
        swap(x[k][i], x[k-1][i]);
        k++;
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << x[i] << '\n';
}
