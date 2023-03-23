#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int main()
{
  read_file();
  int n;
  string x;
  cin >> x >> n;
  sort(x.begin(), x.end()); 
  n--;
  while(n--)
    next_permutation(x.begin(), x.end()); 
  cout << x <<"\n"; 
}
