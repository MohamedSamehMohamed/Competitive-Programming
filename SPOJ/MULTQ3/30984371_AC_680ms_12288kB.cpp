// Author : Mohamed sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 19;
int seg[N][4];
int n, q, ty, l, r;
void push(int node)
{
  seg[node][3]%=3;
  int rep = seg[node][3];
  while(rep--)
  {
    int tm = seg[node][0];
    seg[node][0] = seg[node][1];
    seg[node][1] = seg[node][2];
    seg[node][2] = tm;
  }
  int n1 = node * 2 + 1;
  seg[n1][3] += seg[node][3];
  seg[n1+1][3] += seg[node][3];
  seg[node][3]=0;
}
int query(int node = 0, int nst = 0, int nen = n-1)
{
  push(node);
  if (nst > r || nen < l)return 0;
  if (nst >= l && nen <= r)
    return seg[node][0];
  int m = (nst+nen)>>1;
  return query(node * 2 + 1, nst, m) + query(node * 2 + 2, m+1, nen);
}
void update(int node = 0, int nst = 0, int nen = n-1)
{
  push(node);
  if (nst > r || nen < l)return;
  if (nst >= l && nen <= r)
  {
    seg[node][3]++;
    push(node);
    return;
  }
  int m = (nst+nen)>>1;
  int n1 = node * 2 + 1;
  update(n1, nst, m);
  update(n1+1, m+1, nen);
  for (int i = 0; i < 3; i++)seg[node][i] = seg[n1][i] + seg[n1+1][i];
}
void build(int node = 0, int nst = 0, int nen = n-1)
{
  if (nst == nen)
  {
    seg[node][0]++;
    return;
  }
  int m = (nst + nen)>>1;
  int n1 = node * 2 + 1;
  build(n1, nst, m);
  build(n1+1, m+1, nen);
  for (int i = 0; i < 3; i++)seg[node][i] = seg[n1][i] + seg[n1+1][i];
}
int main()
{
  scanf("%d%d", &n, &q);
  build();
  while(q--)
  {
    scanf("%d%d%d", &ty, &l, &r);
    if (ty)
      printf("%d\n", query());
    else
      update();
  }
}
