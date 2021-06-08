#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], nxt[N], need[N], n, m, sq;
void cal(int i)
{
  int nx = i + a[i];
  nxt[i] = i;
  need[i] = 0;
  if (nx >= n)
  {
    need[i] = 1;
    return;
  }
  while(nx < n && i / sq == nx / sq)
  {
    need[i]++;
    nxt[i] = nx;
    nx += a[nx];
  }
  if (nx < n)
  {
    nxt[i] = nx;
    need[i]++;
  }
}
void cal2(int i)
{
  int nx = i + a[i];
  nxt[i] = nxt[nx];
  need[i] = 1 + (nx == nxt[nx]? 0: need[nx]);
}
void update(int pos, int value)
{
  a[pos] = value;
  cal(pos);
  int prevoius = pos - 1;
  while(prevoius >= 0 && prevoius / sq == pos / sq)
  {
    if ((prevoius + a[prevoius]) / sq == pos / sq && prevoius + a[prevoius] < n)
      cal2(prevoius);
    prevoius--;
  }
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
 
  sq = sqrt(n) + 1;
  for (int i = 0; i < n; i++)
    cal(i);
 
  while(m--)
  {
    int ty, a, b;
    scanf("%d%d", &ty, &a);
    a--;
    if (ty)
    {
      int lst = a;
      int cnt = 0;
      while(lst < n && nxt[lst] != lst)
      {
        cnt += need[lst];
        lst = nxt[lst];
      }
      cnt += need[lst];
      printf("%d %d\n", lst + 1, cnt);
    }else
    {
      scanf("%d", &b);
      update(a, b);
    }
 
  }
}
