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
const int N = 1e5+1, M = (1<<20);
int Q[M][2],order[M],frq[M],n,m,k;
ll ans[M];
int pre[N], a[N];
ll curans ;
void add (int i)
{
  frq[pre[i]]++;
  curans+=frq[pre[i]^k] ;
  if (pre[i] == (pre[i] ^ k))curans--;
}
void remove (int i)
{
  curans -= frq[pre[i]^k] ;
  if ((pre[i]^k) == pre[i])curans++;
  frq[pre[i]]--;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ;i++)
    {
      cin >> a[i];
      pre[i] = a[i];
      pre[i]^= pre[i-1];
    }
    for (int i =0; i < m ;i++)
    {
      cin >> Q[i][0] >> Q[i][1];
      Q[i][0]--;
      order[i] = i;
    }
    int sq = sqrt(m);
    sort(order, order + m , [sq](int i, int j){
      return MP(Q[i][0]/sq, Q[i][1]) < MP(Q[j][0]/sq,Q[j][1]);
    });
    int l=0, r= -1 ;
    for (int i =0; i< m ;i++)
    {
      int cur = order[i];
      while (l > Q[cur][0])add(--l);
      while (r < Q[cur][1])add(++r);
      while (l < Q[cur][0])remove(l++);
      while (r > Q[cur][1])remove(r--);
      ans[cur] = curans;
    }
    for (int i =0; i < m ;i++)
    {
      cout << ans[i] <<"\n";
    }
}