// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int n, m;
int ar[N];
int buck[500][500];
int main()
{
  scanf("%d%d", &n, &m);
  int sq = 1 + sqrt(n);
  while(m--)
  {
    int ty, a, b, c;
    scanf("%d", &ty);
    if (ty == 1)
    {
      scanf("%d%d%d", &a, &b, &c);
      if (b <= sq)
        buck[b][a] += c;
      else
      {
        while(a <= n)
          ar[a] += c, a += b;
      }
    }else
    {
      scanf("%d", &a);
      int ans = ar[a];
      for (int i = 1; i <= sq; i++)
        ans += buck[i][a%i];
      printf("%d\n", ans);
    }
  }
}
