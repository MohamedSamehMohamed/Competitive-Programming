// Author : Mohamed Sameh
// created in: 9:44 PM
/*
 * answer = t
 * split array to two subsets S1, S2 such that
 * sumOf S1 <= t * f
 * sumOf S2 <= t * w
 * t >= max( sumOf S1 / f, sumOf S2 / w)
 *
 */
#include <bits/stdc++.h>
using namespace std;
int a[100], n, f, w;
bool sums[2][1000001];
void test(){
  scanf("%d %d", &w, &f);
  scanf("%d", &n);
  int total = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), total+=a[i];
  memset(sums, 0, sizeof sums);
  int p = 0;
  sums[p][0] = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < a[i]; j++){
      sums[p^1][j] = sums[p][j];
    }
    for (int j = a[i]; j <= total; j++){
      sums[p^1][j] = sums[p][j] | sums[p][j-a[i]];
    }
    p ^= 1;
  }

  int ans = 1e9;
  for (int i = 0; i <= total; i++){
    if (sums[p][i] == 0)continue;
    for (int _ = 0; _ < 2; _++)
    {
      ans = min(ans, max( (total-i+w-1) / w, (i+f-1) / f ));
      swap(w, f);
    }
  }
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}