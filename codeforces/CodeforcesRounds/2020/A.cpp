// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int t;cin >> t;
  while(t--)
  {
    int n;cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    set<int> dif;
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        dif.insert(v[j]-v[i]);
    cout << dif.size() << '\n';
  }
}
