// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush ff1ush(stdout);
using namespace std ;
const int N = 420, Mx = 1e6;
string x, y, mp = "0123456789";
int n, sz;
int a[N], dp[N][N][2][2], vis[N][N][2][2], Id;
bool oo;
int solve(int idx = 0, int rm = 0, bool f1 = 0, bool f2 = 1)
{
  if (rm < 0||idx>sz+40)return Mx;
  if (!rm)
  {
    if (f1&&idx>=sz&&f2)return 0;
    if (idx > sz)return 0;
  }
  int &ret = dp[idx][rm][f1][f2];
  if (vis[idx][rm][f1][f2] == Id)return ret;
  ret = Mx;
  vis[idx][rm][f1][f2] = Id;
  int mn = (idx < sz? x[idx]-'0': -1);
  for (int i = 0 + !idx; i <= 9; i++)
  {
    ret = min(ret, 1 + solve(idx+1, rm - i, (f1|(i > mn)), (f2&!(!f1&i<mn) )));
  }
  return ret;
}
void build (int idx = 0, int rm = 0, bool f1 = 0, bool f2 = 1)
{
  if (rm < 0 || idx >= N)return;
  if (rm == 0)
  {
    if (f1 && idx >= sz&&f2)return;
    if (idx > sz)return;
  }
  int ret = dp[idx][rm][f1][f2];
  int mn = (idx < sz? x[idx]-'0': -1);
  for (int i = 0 + !idx; i <= 9; i++)
  {
    int pi = 1 + solve(idx+1, rm - i, (f1|(i > mn)), (f2&!(!f1&i<mn) ));
    if (pi == ret)
    {
      y += mp[i];
      build(idx+1, rm - i, (f1|(i > mn)), (f2&!(!f1&i<mn) ));
      break;
    }
  }
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  cin >> a[i];
  x = "0";
  for (int i = 0; i < n; i++)
  {
    Id++;
    sz = SZ(x);
    solve(0, a[i], 0, 1);
    y = "";
    build(0, a[i], 0, 1);
    x = y;
    cout << x <<"\n";
  }
}
