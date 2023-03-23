#include<bits/stdc++.h>
using namespace std;
const int N = 100009, M = 51, mod = 5000000;
int a[N], n, k;
struct bit2D
{
    int tree[N][M];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    int get(int i, int j)
    {
        int  ret = 0;
        for(i++ ; i ; i -= (i & (-i)))
        {
            for(int jj = j + 1 ; jj ; jj -= (jj & (-jj)))
            {
                ret = (ret + tree[i - 1][jj - 1])%mod;
            }
        }
        return ret;
    }
    void add(int i, int j, int  val)
    {
        for(i++ ; i <= N ; i += (i & (-i)))
        {
            for(int jj = j + 1 ; jj <= M ; jj += (jj & (-jj)))
            {
                tree[i - 1][jj - 1] = (tree[i - 1][jj - 1]+ val) % mod;
            }
        }
    }
    int  get(int si, int sj, int ei, int ej)
    {
        return get(ei, ej) - get(ei, sj - 1) - get(si - 1, ej) + get(si - 1, sj - 1);
    }
}dp;
int main()
{
  dp.init();
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i), a[i]++;

  for (int i = 0; i < n; i++)
  {
    dp.add(a[i], 1, 1);
    for (int j = 2; j <= k; j++)
      dp.add(a[i], j, (2 * mod + dp.get(1, j-1, a[i]-1, j-1))%mod );
  }
  printf("%d\n", (dp.get(0, k, N-1, k) + 2 * mod ) % mod);
}
