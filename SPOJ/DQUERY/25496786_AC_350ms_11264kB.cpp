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
const int N = 3e4, M = 2e5, Sz = 1e6+1 ;
int a[N], frq[Sz], Q[M][3], order[M], ans[M], n, q, l, r, dif ;
void add (int i)
{
  if (++frq[a[i]] == 1 )dif++;
}
void remove (int i )
{
  if (--frq[a[i]] == 0 )dif--;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n ;
    for (int i =0; i < n ;i++)cin >> a[i];
    cin >> q ;
    for (int i =0; i < q ;i++){
      cin >> Q[i][0] >> Q[i][1];
      Q[i][0]--;Q[i][1]--;
      Q[i][2] = order[i] = i ;
    }
    int sq = sqrt(q);
    sort(order, order + q ,[sq](int i, int j){
      return MP(Q[i][0] / sq , Q[i][1]) < MP(Q[j][0] / sq , Q[j][1]);
    });
    l = 0, r= -1 ;
    for (int i =0; i < q; i++)
    {
      int cur = order[i];
      while (l > Q[cur][0])add(--l);
      while (r < Q[cur][1])add(++r);
      while (l < Q[cur][0])remove(l++);
      while (r > Q[cur][1])remove(r--);
      ans[Q[cur][2]] = dif;
    }
    for (int i =0; i < q ;i++)
    {
      cout << ans[i] <<"\n";
    }

}
