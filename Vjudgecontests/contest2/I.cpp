// Author : Mohamed Sameh
// created in: 10:27 PM
#include <bits/stdc++.h>
using namespace std;
// nx = x cos(d) - y sin(d)
// ny = x sin(d) + y cos(d)
/*
 * nx - x = dif x
 * ny - y = dif y
 * xcos()-ysin()-x
 * x1 A - y1B - x1 = x2 * A - y2 * B - x2
 *
 * x1 A - x2 A - x1 + x2 = y1B - y2B
 * A * (x1-x2) - x1 + x2 = B(y1-y2)
 * (A-1) * x1 - (A-1) * x2 = B(y1-y2)
 * (A-1) * (x1-x2) = B (y1-y2)
 * lol I discovered the slope
 * same for all pairs
 */
void test2(vector<vector<int>>&a, vector<vector<int>>& b){
  int n = a.size();
  map<vector<int>, int> mp;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int difx = a[i][0] - b[j][0];
      int dify = a[i][1] - b[j][1];
      if (dify == 0){
        difx = 1;
      }else if (difx == 0){
        dify = 1;
      }
      int g = __gcd(abs(difx), abs(dify));
      if (difx * dify < 0){
        difx = -abs(difx);
        dify = abs(dify);
      }else {
        difx = abs(difx);
        dify = abs(dify);
      }
      if (g){
        difx /= g;
        dify /= g;
      }
      mp[{difx, dify}]++;
    }
  }
  for (auto it: mp){
    printf("%d : ", it.second);
    for (int j: it.first) printf("%d ", j);
    printf("\n");
  }
}
void test(){
  int n;
  scanf("%d", &n);
  vector<vector<int>> a(n), b(n);
  for (int i = 0; i < n; i++){
    a[i] = vector<int>(2);
    for (int j = 0; j < 2; j++)
      scanf("%d", &a[i][j]);
  }
  for (int i = 0; i < n; i++){
    b[i] = vector<int>(2);
    for (int j = 0; j < 2; j++)
      scanf("%d", &b[i][j]);
  }
  test2(a, a);
  printf("\n");
  test2(b, b);
  printf("\n");
  test2(a, b);

}
int main()
{
  test();
}