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
const int N = 2e5+1, Sz = 1e6+1 ;
int a[N], frq[Sz], Q[N][3], order[N], n, q, l, r;
ll ans[N], sum, curv ;
void cal(int i)
{
    curv = 1LL*a[i]*frq[a[i]]*frq[a[i]];
    curv = max(0LL,curv);
}
void add (int i)
{
  cal(i);
  sum-=curv ;
  frq[a[i]]++;
  cal(i);
  sum+=curv;
}
void remove (int i )
{
  cal(i);
  sum-=curv;
  frq[a[i]]--;
  cal(i);
  sum+=curv;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q ;
    for (int i =0; i < n ;i++)cin >> a[i];
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
      ans[Q[cur][2]] = sum;
    }
    for (int i =0; i < q ;i++)
    {
      cout << ans[i] <<"\n";
    }

}