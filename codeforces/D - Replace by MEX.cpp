#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int n, a[N], frq[N];
int Mex()
{
  for (int i = 0; i <= n; i++)
    if (frq[i] == 0)return i;
}
bool Sotred()
{
  for (int i = 1; i < n; i++)if (a[i] < a[i-1])return 0;
  return 1;
}
void test()
{
  scanf("%d", &n);
  memset(frq, 0, sizeof frq);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), frq[a[i]]++;
  vector<int> ops;
  while(!Sotred())
  {
    int mx = Mex();
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
      if (a[i] != i)
      {
        idx = i;break;
      }
    }
    if (mx == n)
    {
      ops.push_back(idx+1);
      frq[mx]++;
      frq[a[idx]]--;
      a[idx] = mx;
    }else
    {
      ops.push_back(mx+1);
      frq[mx]++;
      frq[a[mx]]--;
      a[mx] = mx;
    }
  }
  printf("%d\n", ops.size());
  for (int i: ops)printf("%d ", i);
  printf("\n");
}
int main()
{
  int t;scanf("%d", &t);
  while(t--)test();
}
