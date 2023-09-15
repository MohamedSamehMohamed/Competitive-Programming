#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int i = 1, j = 0, tk = 0;
  while(i < n && tk < m)
  {
    if (i >= j)j = i + 1;
    while(j <= n && tk < m)
    {
      tk++;
      if (tk == m)
        break;
      tk++;
      j++;
    }

  }
  printf("%d %d\n", max(0, n - 2 * m), );
}
