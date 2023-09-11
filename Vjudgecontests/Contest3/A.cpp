// Author : Mohamed Sameh
// created in: 8:47 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 16;
int h, w, a, b;
int dp[1<<N][N][N];
int solve(int rowMsk, int row, int remA, int remB){
  if (row == h)
    return rowMsk == 0 && remA + remB == 0;
  int& ret = dp[rowMsk][row][remA];
  if (~ret) return ret;
  ret = 0;
  int space = w;

  for (int tkb = 0; tkb <= remB; tkb++){

  }

}
void test(){
  scanf("%d%d%d%d", &h, &w, &a, &b);

}
int main()
{
  test();
}