// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 18;
int a[N], seg[N<<1], n, q;
char x[35];
vector<int> numbers;
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = a[l];
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = min(seg[n1], seg[n2]);
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
  if (l >= le && r <= re)
    return seg[node];
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  if (re <= m)
    return query(le, re, n1, l, m);
  if (le > m)
    return query(le, re, n2, m+1, r);
  return min(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
}
void update(int pos, int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > pos || r < pos)
    return;
  if (l == r)
  {
    seg[node] = val;
    a[pos] = val;
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  update(pos, val, n1, l, m);
  update(pos, val, n2, m+1, r);
  seg[node] = min(seg[n1], seg[n2]);
}
void updateHelper()
{
  int val = a[numbers[0]-1];
  for (int i = 0; i < numbers.size()-1; i++)
  {
    update(numbers[i]-1, a[numbers[i+1]-1]);
  }
  update(numbers.back()-1, val); 
}
void getInput()
{
  numbers.clear();
  int sz = strlen(x);
  numbers.push_back(0);
  for (int i = 6; i < sz-1; i++)
  {
    if (x[i] == ',')
    {
      numbers.push_back(0);
    }else
    {
      int num = numbers.back();
      numbers.pop_back();
      num = num * 10 + (x[i] - '0');
      numbers.push_back(num);
    }
  }
}
int main()
{
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  gets(x);
  while(gets(x) != NULL)
  {
    getInput();
    if (x[0] == 'q')
    {
      printf("%d\n", query(numbers[0]-1, numbers[1]-1));
    }else
    {
      updateHelper();
    }
  }
}
