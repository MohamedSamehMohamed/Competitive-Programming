// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
int n, m;
int a[N][2];
int a1[N], sz;
int Col[N], pos[N];
// we store all the colums that has a tie on it
// for each column we chek if it has one or two
// if two we can't do any thing ans skip
// if it has one, we must fix it by put horizontal tie
// to be able to put a horizontal tie there must be a next column that has a one tie on it
// and if the tie on the same raw in the two columns, the free columns between must be even
// and odd otherwise
void test()
{
  scanf("%d%d", &n, &m);
  sz = 0;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d", a[i], a[i]+1);
    a1[sz++] = a[i][1];
  }
  sort(a1, a1+sz);
  sz = unique(a1, a1+sz) - a1;
  memset(Col, 0, sizeof Col);
  for (int i = 0; i < m; i++)
  {
    a[i][1] = lower_bound(a1, a1+sz, a[i][1]) - a1;
    Col[a[i][1]]++;
    pos[a[i][1]] = a[i][0]-1;
  }
  bool ok = 1;
  for (int i = 0; i < sz; i++)
  {
    if (Col[i] != 1)continue;
    if (i == sz-1 || Col[i+1] != 1)
    {
      ok = 0;break;
    }
    int l = a1[i];
    int r = a1[i+1];
    bool same = (pos[i] == pos[i+1]);
    int len = r-l-1;
    if (len%2)
    {
      if (same)
      {
        ok = 0;break;
      }
    }else
    {
      if (!same)
      {
        ok = 0;break;
      }
    }
    i++;
  }
  printf("%s\n", (ok? "Yes" : "No"));
 
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
