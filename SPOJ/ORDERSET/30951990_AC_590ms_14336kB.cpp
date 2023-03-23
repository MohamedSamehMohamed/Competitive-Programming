#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
int Q[N], a[N], a1[N], sz, n, q;
char op[N];
int frq[N];
struct BIT
{
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void addHelper(int pos, int val)
    {
        for(++pos ; pos <= N ; pos += (pos & (-pos))) tree[pos - 1] += val;
    }
    void add(int pos, int val)
    {
      if (val == 1)
      {
        if (frq[pos])return;
        frq[pos]++;
        addHelper(pos, 1);
        sz++;
      }else
      {
        if (frq[pos] == 0)return;
        frq[pos]--;
        addHelper(pos, -1);
        sz--;
      }
    }
    int get(int pos)
    {
        pos = min(pos, N-1);
        int ret = 0;
        for(++pos ; pos ; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }
    int kth(int k)
    {
      int l = 0, r = N-1, m, ans = 0;
      while(l <= r)
      {
        m = (l+r) >> 1;
        if (get(m) >= k)
          ans = m, r = m-1;
        else
          l = m+1;
      }
      return ans;
    }
}bit;

int main()
{
  bit.init();
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf(" %c%d", &op[i], &Q[i]);
    a1[sz++] = Q[i];
    a1[sz++] = Q[i]-1;
  }
  sort(a1, a1+ sz);
  sz = unique(a1, a1+sz) - a1;
  for (int i = 0; i < n; i++)if (op[i] != 'K')Q[i] = lower_bound(a1, a1+sz, Q[i]) - a1;
  sz = 0;
  for (int i = 0; i < n; i++)
  {
    switch (op[i]) {
      case 'I':
        bit.add(Q[i], 1);
      break;
      case 'D':
        bit.add(Q[i], -1);
      break;
      case 'K':
        if (Q[i] > sz)
          printf("invalid\n");
        else
          printf("%d\n", a1[bit.kth(Q[i])]);
      break;
      case 'C':
        printf("%d\n", bit.get(Q[i]-1));
      break;
    }
  }
}
