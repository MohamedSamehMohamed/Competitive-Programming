#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, d, h;
int hight[N];
void test(){
  scanf("%d%d%d", &n, &d, &h);
  for (int i = 0; i < n; i++)
    scanf("%d", hight + i);
  long double ans = 0, area = 1.0*d * h / 2.0;
  for (int i = 0; i < n; i++){
    if (i == n-1 || hight[i] + h <= hight[i+1])
      ans += area;
    else {
      int curH = hight[i+1] - hight[i];
      long double upperBase = 1.0 * d * (hight[i] + h - hight[i+1]) / h;
      ans += 1.0 * curH * (upperBase + d) / 2.0;
    }
  }
  printf("%6Lf\n", ans);
}
int main(){
  int t;
  cin >> t;
  while (t--){
    test();
  }
}