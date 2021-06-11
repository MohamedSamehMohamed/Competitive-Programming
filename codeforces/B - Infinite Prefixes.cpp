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
int pre[N][2];
int n, x;
bool inf = 0;
ll Mx = 1e12, ret;
void solveP(int i)
{
  ll l = 0, r = Mx, m, L, R;
  L = R = -1;
  while (l <= r)
  {
    m = (l+r)>>1LL;
    ll cur = m*pre[n][0] + pre[i][0] - m*pre[n][1] - pre[i][1];
    if (cur >= x)
    {
      if (cur == x) L = m;
      r = m-1;
    }else
    {
      l = m+1;
    }
  }
  if (L == -1)return;
  l = L, r = Mx;
  while (l <= r)
  {
    m = (l+r)>>1LL;
    ll cur = m*pre[n][0] + pre[i][0] - m*pre[n][1] - pre[i][1];
    if (cur > x)
    {
      r = m-1;
    }else
    {
      if (cur == x)R = m;
      l = m+1;
    }
  }
  if (R == Mx){
    inf = 1;
    return;
  }
  ret += R - L + 1;
}
void solveN(int i)
{
  ll l = 0, r = Mx, m, L, R;
  L = R = -1;
  while (l <= r)
  {
    m = (l+r)>>1LL;
    ll cur = m*pre[n][0] + pre[i][0] - m*pre[n][1] - pre[i][1];
    if (cur >= x)
    {
      if (cur == x) L = m;
      l = m+1;
    }else
    {
      r = m-1;
    }
  }
  if (L == -1)return;
  l = L, r = Mx;
  while (l <= r)
  {
    m = (l+r)>>1LL;
    ll cur = m*pre[n][0] + pre[i][0] - m*pre[n][1] - pre[i][1];
    if (cur >= x)
    {
      if (cur == x)R = m;
      l = m+1;
    }else
    {
      r = m-1;
    }
  }
  if (R == Mx){
    inf = 1;
    return;
  }
  ret += R - L + 1;
}
int main()
{
  FAST
  int t;
  cin >> t;
  pre[0][0] = 0;
  pre[0][1] = 0;
  while(t--)
  {
    string str;
    cin >> n >> x >> str;
    for (int i = 0; i < n; i++)
    {
      int v = str[i] - '0';
      pre[i+1][v]   = 1 + pre[i][v];
      pre[i+1][v^1] = pre[i][v^1];
    }
    ret = 0;
    inf = 0;
    for (int i = 0; !inf && i < n; i++)
    {
      if (pre[n][0] - pre[n][1] >= 0)
        solveP(i);
      else
        solveN(i);
    }
    if (inf)ret = -1;
    cout << ret <<"\n";
  }
 
 
}
