#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, M = 5e4 + 9;
int a[M], Q[M][3], ord[M], answer[M], n, q, k, tot;
struct BIT
{
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void add(int pos, int val)
    {
        if (pos > N)return;
        for(++pos ; pos <= N ; pos += (pos & (-pos))) tree[pos - 1] += val;
    }
    int get(int pos)
    {
        if (pos < 0)return 0;
        int ret = 0;
        for(++pos ; pos ; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }
}bit;
int lessThaneq(int x)
{
  x = min(N-1, x);
  x = max(0, x);
  return bit.get(x);
}
int greaterThaneq(int x)
{
  x = min(N-1, x);
  x = max(0, x);
  return bit.get(N-1) - bit.get(x-1);
}
void add(int idx)
{
  tot += lessThaneq(a[idx] - k);
  tot += greaterThaneq(a[idx] + k);
  bit.add(a[idx], 1);
}
void remove(int idx)
{
  tot -= lessThaneq(a[idx] - k);
  tot -= greaterThaneq(a[idx] + k);
  bit.add(a[idx], -1);
}
int main()
{
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < q; i++)
  {
    scanf("%d%d", Q[i], Q[i]+1);
    Q[i][0]--;
    Q[i][1]--;
    Q[i][2] = i;
    ord[i] = i;
  }
  int sq = sqrt(n) + 1;
  sort(ord, ord + q, [&](int i, int j){
    return make_pair(Q[i][0]/ sq, Q[i][1]) < make_pair(Q[j][0]/ sq, Q[j][1]);
  });
  int l = 0, r = -1;
  for (int i = 0; i < q; i++)
  {
    int cur = ord[i];
    while(l > Q[cur][0])add(--l);
    while(r < Q[cur][1])add(++r);
    while(l < Q[cur][0])remove(l++);
    while(r > Q[cur][1])remove(r--);
    answer[cur] = tot;
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", answer[i]);
}
