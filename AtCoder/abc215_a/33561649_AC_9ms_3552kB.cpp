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
  string s;cin >> s;
  cout << (s == "Hello,World!"? "AC": "WA") << "\n";
}
