// Author : Mohamed Sameh
// created in: 10:08 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
int n, q;
long long a[N];
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
};
void test(){
  scanf("%d%d", &n, &q);
  vector<BIT> adj(30);
  for (int i = 0; i < n; i++)
    scanf("%lld", a+i);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 30; j++){
      if (a[i] & (1<<j))
        adj[j].add(i, 1);
    }
  }
  for (int i = 0; i < q; i++){
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1){
      x--;
      for (int j = 0; j < 30; j++){
        int s1 = (a[x] & (1LL<<j)) != 0;
        int s2 = (y & (1LL<<j)) != 0;
        if (s1 ^ s2 != s1){
          if (s1){
            adj[j].add(x, -1);
          }else {
            adj[j].add(x, 1);
          }
        }
      }
      a[x] ^= y;
    }else {
      long long cur = 0;
      x--;y--;
      for (int i = 0; i < 30; i++){
        int sum = adj[i].get(y) - adj[i].get(x-1);
        if (sum % 2)
          cur |= (1LL<<i);
      }
      printf("%lld\n", cur);
    }
  }
}
int main()
{
  test();
}