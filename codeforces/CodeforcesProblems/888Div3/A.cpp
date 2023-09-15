// Author : Mohamed Sameh
// created in: 11:32 PM
#include <bits/stdc++.h>
using namespace std;
int n, m, k, h;
void test(){
  scanf("%d%d%d%d", &n, &m, &k, &h);
  int cnt = 0;
  for (int i = 0; i < n; i++){
    int hi;
    scanf("%d", &hi);
    int dif = abs(h - hi);
    /*
     * two people one stand in step i and the other on step j (i <= j)
     * j * k - i * k = dif
     * k * (j-i) = dif
     * j-i = dif / k
     * i != j, so dif / k > 0
     * i, j take values from [1:m], i <= j, j-i <= m-1, so dif / k <= m - 1
     */
    cnt += (dif % k == 0 && dif / k <= m-1 && dif / k > 0);
  }
  printf("%d\n", cnt);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}