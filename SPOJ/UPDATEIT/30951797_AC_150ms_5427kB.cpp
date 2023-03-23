#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int a[N], n, q;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &q);
    memset(a, 0, sizeof a);
    while(q--)
    {
      int l, r, val;
      scanf("%d%d%d", &l, &r, &val);
      a[l]+=val;a[r+1]-=val;
    }
    for (int i = 1; i < N; i++)a[i] += a[i-1];
    scanf("%d", &q);
    while(q--)
    {
      int pos;scanf("%d", &pos);
      printf("%d\n", a[pos]);
    }
  }
}
