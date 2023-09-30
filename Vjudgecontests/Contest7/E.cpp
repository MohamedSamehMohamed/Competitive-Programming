// Author : Mohamed Sameh
// created in: 9:02 PM
#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
int val[26];
string tot;
bool can(){
  long long num1 = 0, num2 = 0, num3 = 0;
  for (int i = 0; i < s1.size(); i++){
    num1 = num1 * 10 + val[s1[i]-'a'];
  }
  for (int i = 0; i < s2.size(); i++){
    num2 = num2 * 10 + val[s2[i]-'a'];
  }
  for (int i = 0; i < s3.size(); i++){
    num3 = num3 * 10 + val[s3[i]-'a'];
  }
  if (num1 + num2 == num3){
    cout << num1 << "\n" << num2 <<"\n" << num3 <<"\n";
    return 1;
  }
  return 0;
}
void solve(int i, int msk){
  if (i == tot.size()){
    if (can()){
      exit(0);
    }
    return;
  }
  for (int d = 0; d <= 9; d++){
    if (msk & (1<<d)) continue;
    if (s1[0] == tot[i] || s2[0] == tot[i] || s3[0] == tot[i]){
      if (d == 0) continue;
    }
    val[tot[i] - 'a'] = d;
    solve(i+1, msk | (1<<d));
    val[tot[i] - 'a'] = -1;
  }
}
void test(){
  cin >> s1 >> s2 >> s3;
  tot = s1 + s2 + s3;
  sort(tot.begin(), tot.end());
  tot.erase(unique(tot.begin(), tot.end()) , tot.end());
  memset(val, -1, sizeof val);
  solve(0, 0);
  cout << "UNSOLVABLE\n";
}
int main()
{
  test();
}