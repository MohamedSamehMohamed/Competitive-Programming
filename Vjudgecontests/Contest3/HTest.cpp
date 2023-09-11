// Author : Mohamed Sameh
// created in: 11:01 PM
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> temp;
vector<vector<int>> v;
void solve(){
  if (temp.size() == n){
    v.push_back(temp);
    return;
  }
  for (int i = 1; i <= k; i++){
    temp.push_back(i);
    solve();
    temp.pop_back();
  }
}
void testIt(){
  v.clear();
  solve();
  long long sum = 0;
  for (int i = 0; i < v.size(); i++){
    int g = 0;
    for (int j: v[i])
      g = __gcd(j, g);
    sum += g;
  }
  printf("%lld\n", sum);
}
void test(){

}
int main()
{
  test();
}