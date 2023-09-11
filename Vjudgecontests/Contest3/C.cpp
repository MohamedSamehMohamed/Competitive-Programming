// Author : Mohamed Sameh
// created in: 9:13 PM
#include <bits/stdc++.h>
using namespace std;
double x, y, r;
bool inCircle(double xcor, double ycor){
  cout << 1LL * (xcor-x) * (xcor-x) +
          1LL * (ycor-y) * (ycor-y) << " " << 1LL * r * r<<"\n";
  1LL * (xcor-x) * (xcor-x) +
  1LL * (ycor-y) * (ycor-y) <= 1LL * r * r;
}
void test(){
  scanf("%f%f%f", &x, &y, &r);
  int up, down, left, right;
  up = 0;down = -1;
  left = -1; right = 0;
  int l = -(4e5+9), r = int(x), m;
  while (l <= r){
    m = (l+r) >> 1;
    if (inCircle(m, y)){
      left = m;
      r = m - 1;
    }else
      l = m + 1;
  }
  printf("%d\n", left);
}
int main()
{
  test();
}