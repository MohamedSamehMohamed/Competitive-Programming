#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int a[1000][2];
vector<int> get_slope(int xx, int yy){
  int up = yy - y;
  int down = xx - x;
  int g = __gcd(up, down);
  up /= g;
  down /= g;
  if (up == 0 && down == 0) return {0, 0};
  if (up == 0) return {0, 1};
  if (down == 0) return {1, 0};
  return {up, down};
}
void test(){
  scanf("%d%d%d", &n, &x, &y);
  set<vector<int>> slopes;
  int xx, yy;
  for (int i = 0; i < n; i++){
    scanf("%d%d", &xx, &yy);
    slopes.insert(get_slope(xx, yy));
  }
  printf("%d\n", (int)slopes.size());

}
int main()
{
  test();
}