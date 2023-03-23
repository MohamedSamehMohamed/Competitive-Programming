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
const int N = 2e5 + 1;
int a[N],a1[N],Q[N][2],order[N],frq[N],FOF[N],n,q,dif;
ll ans[N], sum;
void add (int i)
{
  //FOF[ frq[a[i]] ]--;
  frq[a[i]]++;
  FOF[frq[a[i]]]++;
  sum += FOF[frq[a[i]]];
}
void remove (int i)
{
  sum -= FOF[frq[a[i]]];
  FOF[ frq[a[i]] ]--;
  frq[a[i]]--;
}
void debug ()
{
  printf ("**********\n");
  for (int i =0 ; i <= 10 ;i++)
  {
    printf ("%d ", frq[i]);
  }
  printf ("\n");
  for (int i =1 ;i <= 10; i++)
  {
    printf ("%d ", FOF[i]);
  }
  printf ("\n**********\n");

}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i =0 ; i < n ;i++)
    {
      scanf("%d",a+i);
      a1[i] = a[i];
    }
    sort(a1, a1+ n);
    int sz = unique(a1, a1+n) - a1 ;
    for (int i =0; i < n ;i++)
    {
      a[i] = lower_bound(a1, a1+sz,a[i])-a1;
    }
    for (int i =0; i < q ;i++)
    {
      scanf("%d%d", Q[i], Q[i]+1);
      Q[i][0]--;Q[i][1]--;
      order[i]=i;
    }
    int sq = sqrt(q);
    sort(order, order+q , [sq](int i, int j){
      return MP(Q[i][0]/sq, Q[i][1]) < MP(Q[j][0]/sq, Q[j][1]);
    });
    int l =0, r =-1 ;
    for (int i =0; i < q; i++)
    {
      int cur = order[i];
      while (l > Q[cur][0])add(--l);
      while (r < Q[cur][1])add(++r);
      while (l < Q[cur][0])remove(l++);
      while (r > Q[cur][1])remove(r--);
      ans[cur] = sum;
      //debug();
    }
    for (int i =0; i < q ;i++)
    {
      printf ("%lld\n", ans[i]);
    }
}
