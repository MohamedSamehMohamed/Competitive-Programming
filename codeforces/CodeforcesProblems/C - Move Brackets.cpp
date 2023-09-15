// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
void solve()
{
  int n;
  string x;
  cin >> n >> x;
  int op = 0;
  for (int i = 0; i < n; i++)
  {
    if (x[i] == '(')
      op++;
    else if(op)
      op--;
  }
  cout << op <<"\n";
}
int main()
{
  int t;cin >> t;
  while(t--)
  {
    solve();
  }
}
