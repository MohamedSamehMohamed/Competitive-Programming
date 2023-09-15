// Author : Mohamed Sameh
// created in: 9:17 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int k;
  string s;
  cin >> k >> s;
  vector<int> p;
  int n = s.size();
  for (int i = 0; i < n; i++){
    if (s[i] == '1')
      p.push_back(i);
  }

  long long ans = 0;
  if (k == 0){
    for (int i = 0; i < n; i++){
      if (s[i] == '1') continue;
      int j = i + 1;
      while (j < n && s[j] == '0')
        j++;
      int len = j - i;
      i = j - 1;
      ans += (1LL * len * (len+1)) / 2;
    }
    cout << ans << "\n";
    return;
  }
  for (int i = k-1; i < p.size(); i++){
    int before = p[i-k+1] - (i-k>=0? p[i-k]+1: 0);
    int after = (i+1 < p.size()? p[i+1] - p[i] - 1: n - p[i] - 1);
    ans += (1LL * (before + 1) * (after + 1));
  }
  cout << ans <<"\n";
}
int main()
{
  test();
}