// Author : Mohamed Sameh
// created in: 10:19 PM
#include <bits/stdc++.h>
using namespace std;
long long n;
bool ok(int num){
  string s = to_string(num);
  long long a = 0;
  int len = 2 * (int)s.size();
  for (int i = 0; len--;i=(i+1)%(int)s.size()){
    a = a * 10 + (s[i] - '0');
  }
  return a <= n;
}
void test(){
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= 1000000; i++){
    if (ok(i))
      ans++;
  }
  cout << ans << "\n";
}
int main()
{
  test();
}