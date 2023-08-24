#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
void test()
{
  
}
int main()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout <<"if (i == " << i << " && j == " << j << " && c" << i << j << " == FLAGGED_MINE)\n  return true;\n";
      cout <<"if (i == " << i << " && j == " << j << " && c" << i << j << " == UNFLAGGED_MINE)\n  return false;\n";
    }
  }
}