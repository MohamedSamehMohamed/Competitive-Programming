// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int a[N], n;
int suf[N];
int spt[N][20], LOG[N];
pair<int,int> get(int mx, int le)
{
  int l = le, r = n-1, m, L, R;
  L = R = -1;
  while(l <= r)
  {
    m = (l+r)>>1;
    if (suf[m] > mx)
      l = m+1;
    else
    {
      if (suf[m] == mx)
        L = m;
      r = m-1;
    }
  }
  if (L == -1)return {-1, -1};
  l = L, r = n-1;
  while(l <= r)
  {
    m = (l+r)>>1;
    if (suf[m] < mx)
      r = m-1;
    else
      {
        R = m;
        l = m+1;
      }
  }
  return {L, R};
}
void build()
{
  for (int i = 0; i < n; i++)
    spt[i][0] = a[i];
  for (int j = 1; j < 20; j++)
    for (int i = 0; i + (1<<j) <= n; i++)
    {
      spt[i][j] = min(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
    }
}
int rng(int l, int r)
{
  int sz = LOG[r-l+1];
  return min(spt[l][sz], spt[r-(1<<sz)+1][sz]);
}
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  suf[n-1] = a[n-1];
  for (int i = n-2; i >= 0; i--)
    suf[i] = max(suf[i+1], a[i]);
  int curmax = 0;
  int x, y, z;
  x = -1;
  for (int i = 0; i < n; i++)
  {
    curmax = max(curmax, a[i]);
    pair<int, int> cur = get(curmax, i+2);
    if (cur.first == -1)continue;
    int R = cur.second-1;
    int l = i+2, 


  }
}
int main()
{
  for (int i = 1; i < N; i++)
    LOG[i] = log2(i);
  int t;
  scanf("%d", &t);
  while(t--)
  {
    test();
  }
}
