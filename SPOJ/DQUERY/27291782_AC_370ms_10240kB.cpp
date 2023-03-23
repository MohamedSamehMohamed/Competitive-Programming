// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 3e5+2, M = 1e6+9;
int a[N],Q[N][2], order[N], ans[N], n, q ;
int frq[M], dif;
void add (int i)
{
  if (++frq[a[i]] == 1)dif++;
}
void remove(int i)
{
  if (--frq[a[i]] == 0)dif--;
}
int main()
{
    scanf("%d", &n);
    for (int i =0 ; i < n ;i++)scanf("%d", a+i);
    scanf("%d", &q);
    for (int i =0 ; i < q; i++)
    {
      for (int j =0 ; j < 2; j++)
        scanf("%d", Q[i] + j);
      Q[i][0]--;
      Q[i][1]--;
      order[i]=i;
    }
    int sq = sqrt(q);
    sort(order, order + q, [sq](int i, int j){
      return make_pair(Q[i][0]/sq,Q[i][1]) < make_pair(Q[j][0]/sq,Q[j][1]);
    });
    int l=0 , r= -1, cur;
    for (int i =0; i < q; i++)
    {
      cur = order[i];
      while (l > Q[cur][0])add(--l);
      while (r < Q[cur][1])add(++r);
      while (l < Q[cur][0])remove(l++);
      while (r > Q[cur][1])remove(r--);
      ans[cur] = dif;
    }
    for (int i =0 ;i < q;i++)
    printf("%d\n", ans[i]);
}
