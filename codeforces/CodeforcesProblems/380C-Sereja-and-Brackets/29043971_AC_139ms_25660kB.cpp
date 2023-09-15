// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 20;
struct Node{
  int correct, open, close;
  Node(){}
  Node(int correct, int open, int close)
  {
    this->correct = correct;
    this->open = open;
    this->close = close;
  }
  Node(char c)
  {
    correct = open = close = 0;
    if (c == '(')
      open++;
    else
      close++;
  }
}seg[N<<1];
Node merge(Node l, Node r)
{
  Node ret;
  int mn = min(l.open,r.close);
  ret.correct = l.correct + r.correct + mn;
  ret.open = l.open - mn + r.open;
  ret.close = r.close - mn + l.close;
  return ret;
}
int n, q;
char x[N];
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = Node(x[l]);
    return;
  }
  int m = (l+r) >> 1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
Node query(int le, int re, int node = 0, int l = 0, int r = n-1)
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
  return merge(query(le, re, n1, l, m), query(le, re, n2, m+1, r));
}
int main()
{
  scanf(" %s", x);
  n = strlen(x);
  build();
  scanf("%d", &q);
  while(q--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;r--;
    printf("%d\n", 2 * query(l, r).correct);
  }
}
