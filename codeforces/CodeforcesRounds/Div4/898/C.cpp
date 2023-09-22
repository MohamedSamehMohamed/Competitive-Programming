// Author : Mohamed Sameh
// created in: 4:37 PM
#include <bits/stdc++.h>
using namespace std;
string s[10];
void test(){
  for (int i = 0; i < 10; i++)
    cin >> s[i];
  int p = 0;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (s[i][j] == '.') continue;
      int r = min(i, 10 - i - 1);
      int c = min(j, 10 - j - 1);
      p += min(r, c) + 1;
    }
  }
  cout << p <<"\n";
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}