// Author : Mohamed Sameh
// created in: 4:37 PM
#include <bits/stdc++.h>
using namespace std;
int frq[55], frq2[55];
void test(){
  int n;
  memset(frq2, 0, sizeof frq2);
  scanf("%d", &n);
  vector<vector<int>> sets(n);
  for (int i = 0; i < n; i++){
    int sz;scanf("%d", &sz);
    sets[i] = vector<int>(sz);
    for (int j = 0; j < sz; j++)
    {
      scanf("%d", &sets[i][j]);
      frq2[sets[i][j]]++;
    }
  }
  int total = 0;
  for (int i = 1; i <= 50; i++)
    total += (frq2[i] > 0);
  int ans = 0;
  for (int num = 1; num <= 50; num++){
    if (frq2[num] == 0) continue;
    memset(frq, 0, sizeof frq);
    for (int i = 0; i < n; i++){
      bool add = 1;
      for (int j: sets[i])
        add &= (j != num);
      if (add)
      {
        for (int j: sets[i])
          frq[j]++;
      }
    }
    int cur = 0;
    for (int i = 1; i <= 50; i++)
      cur += (frq[i] > 0);
    ans = max(ans, cur);
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