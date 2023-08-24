// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int a[100], b[100];
int main()
{
  int m = 1;
  while(m, cin>>m, m)
  {
    cout << m <<"\n";
  }
  cout <<"STAR\n";
  int t;cin>>t;
  while(t--)
  {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    bool ok = 1;
    for (int i = 0, j = n-1; i < n; i++, j--)
    {
      if (a[i] + b[j] > x)
      {
        ok = 0;
        break;
      }
    }
    if (ok)
      cout <<"Yes\n";
    else
      cout <<"No\n";
  }
}
