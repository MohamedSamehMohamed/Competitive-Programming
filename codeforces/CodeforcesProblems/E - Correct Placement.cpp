// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9, INF = 1e9;
int n, a[N][2], a1[3*N], ans[N], bit[3*N][2], order[N], len, sz;
int getmin(int r)
{
  int ret = INF, idx = -1;
  for (; r >= 0; r = (r & (r + 1)) - 1)
  {
    if (bit[r][0] < ret)
    {
      ret = bit[r][0];
      idx = bit[r][1];
    }
  }
  return idx;
}
void update(int idx, int val1, int val2)
{
  for (; idx < sz; idx = idx | (idx + 1))
  {
    if (bit[idx][0] > val1)
    {
      bit[idx][0] = val1;
      bit[idx][1] = val2;
    }
  }
}
void init()
{
  for (int i = 0; i < n; i++)
  {
    ans[i]  = -1;
    order[i] = i;
  }
}
void initBit()
{
  for (int i = 0; i < sz; i++)
  {
    bit[i][0] = INF;
    bit[i][1] = -1;
  }
}
int get(int x)
{
  return lower_bound(a1, a1+sz, x) - a1;
}
void Compress()
{
  sz = 0;
  for (int i = 0; i < n; i++)
  {
    a1[sz++] = a[i][0]-1;
    a1[sz++] = a[i][0];
    a1[sz++] = a[i][1];
  }
  sort(a1, a1+sz);
  sz = unique(a1, a1+sz) - a1;
}
void test()
{
  scanf("%d", &n);
  init();
  for (int i = 0; i < n; i++)
    scanf("%d%d", a[i], a[i]+1);
  Compress();
  initBit();
  sort(order, order+n, [](int i, int j){return a[i][0] < a[j][0];});
  for (int i = 0; i < n; i++)
  {
    // find for the pair [a[i][0], a[i][1]]
    // a pair [a[j][0], a[j][1]],, all j -> {0:i-1} a[j][0] <= a[i][0]
    // so find for range [0:a[i][0]-1] min value of a[j][1]
    int cur = order[i];
    int l = get(a[cur][0]);
    int r = get(a[cur][1]);
    int le = get(a[cur][0]-1);
    int mnIdx = getmin(le);
    if (~mnIdx && get(a[mnIdx][1]) < r)
    {
      ans[cur] = mnIdx + 1;
    }
    update(l, r, cur);
  }
  initBit();
  // update all b values
  // for each pair [a[i][0],a[i][1]] find min in range [0, a[i][0]-1] if returned less than a[i][1] then returned is answer:
  for (int i = 0; i < n; i++)
  {
    int l = get(a[i][0]);
    int r = get(a[i][1]);
    update(r, l, i);
  }
  for (int i = 0; i < n; i++)
  {
    if (~ans[i])continue;
    int le = get(a[i][0]-1);
    int mnIdx = getmin(le);
    if (~mnIdx && get(a[mnIdx][0]) < get(a[i][1]))
    {
      ans[i] = mnIdx + 1;
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", ans[i], (i+1==n? '\n': ' '));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
