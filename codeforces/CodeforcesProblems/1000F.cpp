#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
int a[N], a1[N], Q[N][3], ord[N], answer[N], frq[N], bucket[N], n, q, B, sz, Cnt;
void add(int idx)
{
  if (++frq[a[idx]] == 1)
  {
    bucket[a[idx]/B]++;
    Cnt++;
  }else if (frq[a[idx]] == 2)
  {
    Cnt--;
    bucket[a[idx]/B]--;
  }
}
void remove(int idx)
{
  if (--frq[a[idx]] == 1)
  {
    Cnt++;
    bucket[a[idx]/B]++;
  }else if (frq[a[idx]] == 0)
  {
    Cnt--;
    bucket[a[idx]/B]--;
  }
}
int getAnswer()
{
  if (Cnt == 0)return 0;
  for (int i = 0; i < B; i++)
    if (bucket[i])
      for (int j = i * B; ;j++)
        if (frq[j] == 1)
          return j;
  return 0;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  B = 750;
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
    while(l > Q[cur][0])add(--l);
    while(r < Q[cur][1])add(++r);
    while(l < Q[cur][0])remove(l++);
    while(r > Q[cur][1])remove(r--);
    answer[cur] = getAnswer();
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", answer[i]);
}
