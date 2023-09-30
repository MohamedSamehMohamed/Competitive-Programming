// Author : Mohamed Sameh
// created in: 5:05 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, M = 31;
int pre[N][M];
int n, a[N], q;
void test(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < M; i++)
    pre[0][i] = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j < M; j++){
      pre[i][j] = (a[i] & (1LL << j)) != 0;
      pre[i][j] += pre[i-1][j];
    }
  }
  scanf("%d", &q);
  while (q--){
    int l, k;
    scanf("%d%d", &l, &k);
    int left = l, right = n, m, ans = -1;
    while (left <= right){
      m = (left + right) >> 1;
      long long cur = 0;
      for (int i = 0; i < M; i++){
        int sm = pre[m][i] - pre[l-1][i];
        if (sm == m - l + 1)
          cur |= (1LL << i);
      }
      if (cur >= k)
        ans = m, left = m + 1;
      else
        right = m - 1;
    }
    printf("%d ", ans);
  }
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}