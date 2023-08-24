// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
string x;
int n, q;
int main()
{
    int t;cin>>t;
    while(t--)
    {
      cin >> n >> q;
      cin >> x;
      while(q--)
      {
        int l, r;
        cin >> l >> r;
        l--;r--;
        bool ok  = 0;
        for (int i = 0; !ok && i < l; i++) ok |= (x[l] == x[i]);
        for (int i = r+1; !ok && i < n; i++) ok |= (x[r] == x[i]);
        if (ok)
          cout <<"YES\n";
        else
          cout <<"NO\n";
      }
    }
}
