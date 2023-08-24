// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 505;
int n, m;
string x[N];
int pre[N][N];
bool can(int stx, int sty, int k)
{
  for (int i = 1; i <= k; i++)
  {
    int row = stx + i - 1;
    int stcl = sty - i + 1;
    int encl = sty + i - 1;
    if (row >= n || row < 0 || min(stcl, encl) < 0 || max(stcl, encl) >= m)
      return 0;
    bool ok = ((encl-stcl+1) == pre[row][encl] - (stcl-1>=0? pre[row][stcl-1]: 0));
    if (!ok)return 0;
  }
  return 1;
}
void test()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      pre[i][j] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      pre[i][j] = (x[i][j] == '*');
      if (j)pre[i][j] += pre[i][j-1];
    }
  }
  long long cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (x[i][j] == '.')continue;
      int l = 1, r = n, ans = 0;
      while(l <= r)
      {
        int mid = (l+r)>>1;
        if (can(i, j, mid))
          ans = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      cnt += ans;
    }
  cout << cnt << '\n';
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    test();
  }
}
