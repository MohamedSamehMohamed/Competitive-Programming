#include<bits/stdc++.h>
using namespace std;
string s[3];
bool isWin(char c){
  for (int i = 0; i < 3; i++){
    if (s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][0] == c)
      return 1;
    if (s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[0][i] == c)
      return 1;
  }
  if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] == c)
    return 1;
  if (s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[0][2] == c)
    return 1;
  return 0;
}
void test(){
  cin >> s[0] >> s[1] >> s[2];
  string x = "+XO";
  for (int i = 0; i < 3; i++){
    if (isWin(x[i])){
      cout << x[i] << "\n";
      return;
    }
  }
  cout << "DRAW\n";
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}