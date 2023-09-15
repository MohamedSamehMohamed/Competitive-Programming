#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, M = 5e4 + 9;
int a[M], Q[M][3], ord[M], answer[M], n, q, tot;
map<int, int> mp;
int prefix[N];
void update(int idx)
{
  tot ^= a[idx];
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  prefix[0] = a[0];
  for (int i = 1; i < n; i++)prefix[i] = prefix[i-1] ^ a[i];
  scanf("%d", &q);
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
    while(l > Q[cur][0])update(--l);
    while(r < Q[cur][1])update(++r);
    while(l < Q[cur][0])update(l++);
    while(r > Q[cur][1])update(r--);
    answer[cur] = prefix[Q[cur][1]] ^ (Q[cur][0]-1>=0? prefix[Q[cur][0]-1]: 0) ^ tot;
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", answer[i]);
}
