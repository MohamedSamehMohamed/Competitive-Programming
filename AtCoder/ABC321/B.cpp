// Author : Mohamed Sameh
// created in: 2:02 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int n, x;
  cin >> n >> x;
  vector<int> v(n-1);
  int sum = 0;
  for (int i = 0; i < n-1; i++)
  {
    cin >> v[i];
    sum += v[i];
  }
  for (int i = 0; i <= 100; i++){
    int mn = i;
    int mx = i;
    for (int j = 0; j < n-1; j++){
      mn = min(mn, v[j]);
      mx = max(mx, v[j]);
    }
    if (sum + i - (mn + mx) >= x){
      cout << i <<"\n";
      return;
    }
  }
  cout << "-1\n";
}
int main()
{
  test();
}