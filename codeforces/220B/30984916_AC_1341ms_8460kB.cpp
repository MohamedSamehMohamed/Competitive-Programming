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
const int N = 1e5;
int a[N], Q[N][3], order[N], ans[N], n, q, l, r, cur_ans;
unordered_map<int,int> frq;
bool GE (int i)
{
  return frq[ a[i] ] == a[i];
}
void Handle(int i, int val)
{
  cur_ans-=GE(i);
  frq[a[i]]+=val;
  cur_ans+=GE(i);
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
      while (l > Q[cur][0])Handle(--l, 1);
      while (r < Q[cur][1])Handle(++r, 1);
      while (l < Q[cur][0])Handle(l++, -1);
      while (r > Q[cur][1])Handle(r--, -1);
      ans[Q[cur][2]] = cur_ans;
    }
    for (int i =0; i < q ;i++)
    {
      cout << ans[i] <<"\n";
    }

}