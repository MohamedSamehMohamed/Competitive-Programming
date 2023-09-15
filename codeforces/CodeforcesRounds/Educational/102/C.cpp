// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 9;
int a[N], b[N], p[N], ans[N], best[N], n, k;
long long sum(int x)
{
  return (1LL*x * (x+1))/2;
}
int counT()
{
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++)
      cnt += (b[i] > b[j]);
  return cnt;
}
void take()
{
  for (int i = 1; i <= n; i++)
  {
    if (best[i] > b[i])return;
    if (best[i] < b[i])break;
    if (i == n)return;
  }
  for (int i = 1; i <= n; i++)best[i] = b[i];
  for (int i = 1; i <= k; i++)ans[i] = p[i];
}
void test()
{
  scanf("%d%d", &n, &k);
  int cur = 1;
  bool add = 1;
  for (int i = 1; i <= n; i++)
  {
    a[i] = cur;
    best[i] = cur;
    b[i] = cur;
    if (add && cur + 1 <= k)
      cur++;
    else
    {
      add = 0;
      cur--;
    }
  }
  for (int i = 1; i <= k; i++)
    p[i] = i;
  int mx = counT();
  do{
    for (int i = 1; i <= n; i++)
      b[i] = p[a[i]];
    int cnt = counT();
    if (cnt <= mx)
    {
      take();
    }
  }while(next_permutation(p+1, p+k+1));
  for (int i = 1; i <= k; i++)
    printf("%d ", ans[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
