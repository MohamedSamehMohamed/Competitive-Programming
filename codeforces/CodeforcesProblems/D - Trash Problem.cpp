// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e5+9;
int a[N], n, q;
set<int> st, dif;
map<int,int> dif_frq;
int sum, mx;
pair<int,int> ab(int x)
{
  pair<int,int> ret;
  ret.f = ret.s = -1;
  if (st.empty())return ret;
  auto it = st.lower_bound(x);
  if (it != st.end())ret.s = *it;
  if (it != st.begin())
  {
    it--;
    ret.f = *it;
  }
  return ret;
}
void add(int x)
{
  auto ret = ab(x);
  st.insert(x);
  if (~ret.f && ~ret.s && --dif_frq[ret.s - ret.f] == 0)dif.erase(ret.s - ret.f);
  if (~ret.f && ++dif_frq[x - ret.f] == 1)dif.insert(x - ret.f);
  if (~ret.s && ++dif_frq[ret.s - x] == 1)dif.insert(ret.s - x);
  if (~ret.f && ~ret.s)sum -= (ret.s - ret.f);
  if (~ret.f) sum += x - ret.f;
  if (~ret.s) sum += ret.s - x;
}
void remove(int x)
{
  st.erase(x);
  auto ret = ab(x);
  if (~ret.f && ~ret.s && ++dif_frq[ret.s - ret.f] == 1)dif.insert(ret.s - ret.f);
  if (~ret.f && --dif_frq[x - ret.f] == 0)dif.erase(x - ret.f);
  if (~ret.s && --dif_frq[ret.s - x] == 0)dif.erase(ret.s - x);
  if (~ret.f && ~ret.s)sum += (ret.s - ret.f);
  if (~ret.f) sum -= x - ret.f;
  if (~ret.s) sum -= ret.s - x;
}
int get_mx()
{
  if (dif.empty())return 0;
  auto it = dif.end();
  it--;return *it;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)scanf("%d", a+i), st.insert(a[i]);
    sort(a, a+n);
    for (int i = 1; i < n; i++)
    {
      int cur = a[i] - a[i-1];
      sum += cur;
      mx = max(mx, cur);
      if (++dif_frq[cur] == 1)dif.insert(cur);
    }
    printf("%d\n", sum - mx);
    while(q--)
    {
      int ty, x;
      scanf("%d%d", &ty, &x);
      if (ty)
        add(x);
      else
        remove(x);
      mx = get_mx();
      printf("%d\n", sum - mx);
    }
}
