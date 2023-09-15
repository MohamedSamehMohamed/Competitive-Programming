#include <bits/stdc++.h>
using namespace std;
void test(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> pre(n + 1);
  pre[0] = 0;
  for (int i = 0; i < n; i++){
    pre[i+1] = pre[i] + (s[i] == '0');
  }
  int mn = min(pre[n], n - pre[n]);
  for (int i = 0; i < n; i++){
    mn = min(mn, pre[i+1] + (n - i - 1) - pre[n] + pre[i+1]);
    mn = min(mn, (i+1) - pre[i+1] + pre[n] - pre[i+1]);
  }
  printf("%d\n", mn);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}