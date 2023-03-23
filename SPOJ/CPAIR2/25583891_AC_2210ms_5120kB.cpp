// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define MP make_pair
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 4e5, M = 1e5+1;
int n, m, k;
int a[N], Q[N][2], order[N];
int ans[N], fen[N], curans;
int Squery(int r)
{
    r =min (r, M-1);
    int sum = 0 ;
    while (r >= 0 )
    {
      sum += fen[r];
      r = (r & (r+1)) -1 ;
    }
    return sum ;
}
void update (int idx, int val)
{
  while (idx < M)
  {
    fen[idx] += val;
    idx|=(idx+1);
  }
}
void add(int i)
{
  curans += Squery(a[i]-k);
  curans += (Squery(M-1) - Squery(a[i]+k-1));
  update(a[i], 1);
}
void remove (int i)
{
  update(a[i], -1);
  curans -= Squery(a[i]-k);
  curans -= (Squery(M-1)-Squery(a[i]+k-1));
}
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a+i);
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d", Q[i], Q[i]+1);
    order[i] = i;
    Q[i][0]--;
    Q[i][1]--;
  }
  int sq = sqrt(m);
  sort(order, order+m, [sq](int i, int j){
    return MP(Q[i][0]/sq, Q[i][1]) < MP(Q[j][0]/sq, Q[j][1]);
  });
  int l = 0, r = -1 ;
  for (int i = 0; i < m ;i++)
  {
    int cur = order[i];
    while(l > Q[cur][0])add(--l);
    while(r < Q[cur][1])add(++r);
    while(l < Q[cur][0])remove(l++);
    while(r > Q[cur][1])remove(r--);
    ans[cur] = curans;
  }
  for (int i =0 ; i < m; i++)
  {
    printf ("%d\n", ans[i]);
  }
}
