#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int a[N], pre[N], n, q, sq;
struct BIT
{
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void add(int pos, int val)
    {
        for(++pos ; pos <= N ; pos += (pos & (-pos))) tree[pos - 1] += val;
    }
    int get(int pos)
    {
        int ret = 0;
        for(++pos ; pos ; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }
}bit;
int query(int st, int en, int x)
{
    if (st > en)return 0;
    int stB = st / sq, enB = en / sq;
    int ret = 0;
    if(stB == enB)
    {
        for(int i = st ; i <= en ; i++)
        {
            ret += (a[i] < x);
        }
        return ret;
    }
    for(int i = st ; i < (stB + 1) * sq ; i++)
    {
        ret += (a[i] < x);
    }
    for(int i = (enB * sq) ; i <= en ; i++)
    {
        ret += (a[i] < x);
    }
    for(int i = stB + 1 ; i < enB ; i++)
    {
        ret += upper_bound(pre + (i * sq), pre + (i + 1) * sq, x-1) - (pre + (i * sq));
    }
    return ret;
}

void modify(int pos, int val)
{
    int bId = pos / sq;
    int bSt = bId * sq;
    int bEn = min(n, bSt + sq);
    int ind = lower_bound(pre + bSt, pre + bEn, a[pos]) - pre;
    a[pos] = val;
    pre[ind] = val;
    while(ind > bSt && pre[ind - 1] > pre[ind]) swap(pre[ind], pre[ind - 1]), ind--;
    while(ind < bEn - 1 && pre[ind + 1] < pre[ind]) swap(pre[ind], pre[ind + 1]), ind++;
}
int main()
{
  scanf("%d", &n);
  sq = ceil(sqrt(n));
  for(int i = 0, j = 0 ; i < n ; i += sq, j++)
  {
      int k;
      for(k = 0 ; k < sq && k + i < n ; k++)
      {
          scanf("%d", a + i + k);
          pre[i + k] = a[i + k];
      }
      sort(pre + sq * j, pre + sq * j + k);
  }
  long long inversions = 0;
  for (int i = n-1; ~i; i--)
  {
    inversions += bit.get(a[i] - 1);
    bit.add(a[i], 1);
  }
  scanf("%d", &q);
  while(q--)
  {
    int pos, nval;
    scanf("%d%d", &pos, &nval);
    pos--;
    // subtract
    // how many numbers < a[pos] in range [pos + 1, n-1]
    // how many numbers > a[pos] in range [0: pos-1]
    // cout << query(pos + 1, n-1, a[pos]) << " " << pos - query(0, pos-1, a[pos] + 1) << "\n";
    inversions -= query(pos + 1, n-1, a[pos]);
    inversions -= pos - query(0, pos-1, a[pos]+1);

    // a[pos] = nval
    // update
    modify(pos, nval);
    a[pos] = nval;

    // add
    // how many numbers < a[pos] in range [pos + 1, n-1]
    // how many numbers > a[pos] in range [0: pos-1]
    // cout << query(pos + 1, n-1, a[pos]) << " " << pos - query(0, pos-1, a[pos] + 1) << "\n";
    inversions += query(pos + 1, n-1, a[pos]);
    inversions += pos - query(0, pos-1, a[pos]+1);
    printf("%lld\n", inversions);
  }
}
