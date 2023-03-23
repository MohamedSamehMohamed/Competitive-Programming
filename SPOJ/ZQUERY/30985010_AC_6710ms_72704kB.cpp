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
const int N = 5e4 + 20 ;
int pre[N], a1[N], Q[N][2], ans[N], order[N], n, m;
int frq[N];
priority_queue<int> pq ;
deque<int> dq[N] ;
void add (int i)
{
  //cout <<"add:" << i <<" " << pre[i] <<"\n";
  if (!dq[pre[i]].empty())
  {
  frq[ dq[pre[i]].back() - dq[pre[i]].front() ]--;
  if (i > dq[pre[i]].back())
    dq[pre[i]].pb(i);
  else
    dq[pre[i]].push_front(i);
  //cout << dq[pre[i]].back() <<" : " << dq[pre[i]].front() <<"\n";
  frq[ dq[pre[i]].back() - dq[pre[i]].front() ]++;
  pq.push(dq[pre[i]].back() - dq[pre[i]].front());
  }
  else
  {
  dq[pre[i]].pb(i);
  }
}
void remove(int i )
{
  if (!dq[pre[i]].empty())
  {
    frq[ dq[pre[i]].back() - dq[pre[i]].front() ]--;
      if (i == dq[pre[i]].back())
        dq[pre[i]].pop_back();
      else
        dq[pre[i]].pop_front();
  }
  if (!dq[pre[i]].empty())
  {
    frq[ dq[pre[i]].back() - dq[pre[i]].front() ]++;
    pq.push(dq[pre[i]].back() - dq[pre[i]].front());
  }
}
int query ()
{
  while (!pq.empty() && frq[pq.top()] <= 0)
  {
    pq.pop();
  }
  return pq.empty() ? 0 : pq.top();
}
int main()
{
  scanf("%d%d", &n, &m);
  int sz= 1 ;
  a1[0] =0;
  for (int i =1; i <= n ;i++)
  {
    int x ;
    scanf("%d", &x );
    pre[i] = pre[i-1] + x ;
    a1[sz++] = pre[i];
  }
  sort(a1, a1+sz);
  sz = unique(a1, a1+sz) - a1 ;
  for (int i =0 ; i <= n ;i++)
  pre[i] = lower_bound(a1, a1+sz, pre[i]) - a1 ;
  for (int i =0 ;i < m ;i++)
  {
    int l, r ;
    scanf("%d%d", &l, &r);
    Q[i][0] = l-1;
    Q[i][1] = r;
    order[i] = i;
  }
  int sq = sqrt(m);
  sort(order, order+m, [sq](int i, int j){
  return MP(Q[i][0]/sq, Q[i][1]) < MP(Q[j][0]/sq, Q[j][1]);
  });
  int l= 0, r =-1, cur;
  for (int i =0 ; i < m ;i++)
  {
    cur = order[i];
    while (l > Q[cur][0])add(--l);
    while (r < Q[cur][1])add(++r);
    while (l < Q[cur][0])remove(l++);
    while (r > Q[cur][1])remove(r--);
    ans[cur] = query();
  }
  for (int i = 0; i < m; i++)
  {
      cout << ans[i] <<"\n";
  }
}
/*
10 6
1 -1 1 -1 -1 -1 1 1 1 -1
1 10
3 10
5 10
7 10
4 9
2 8
*/
