// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e6 + 9;
bool siev[N];
int main()
{
  siev[0] = siev[1] = 1;
  for (int i = 2; i <= N/i; i++)
  {
    if (siev[i])
      continue;
    for (int j = i*i; j < N; j+=i)
      siev[j] = 1;
  }
  vector<int> p;
  for (int i = 2; i < N; i++)
    if (!siev[i])
      p.push_back(i);
  int n;
  scanf("%d", &n);
  int ans = 0;
  while(n >= 4)
  {
    for (auto i: p)
    {
      int ret = n - i;
      int dif = abs(ret - i);
      if (ret > 0 && (dif % 2 == 0) && !siev[ret])
      {
        // printf("%d %d\n", i, ret);
        n = dif;
        break;
      }
    }
    ans++;
  }
  printf("%d\n", ans);
}
