#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    a[i] = i + 1;
  }
  if (k % 2 != 0){
    cout << "No\n";
    return 0;
  }
  int i = 0, j = n-1;
  while (k > 0 && i < j){
    while ((j-i) * 2 > k)
    {

    }
  }

}