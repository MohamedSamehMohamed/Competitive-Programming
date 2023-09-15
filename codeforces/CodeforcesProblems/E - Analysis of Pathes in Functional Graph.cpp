// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 1e5+9, Lg = 37;
int n, up[N][Lg], mn[N][Lg];
ll k, sum[N][Lg];
int main()
{
 cin >> n >> k;
 for (int i = 0; i < n; i++)
 {
  int p;
  cin >> p;
  up[i][0] = p;
 }
 for (int i = 0; i < n; i++)
 {
  int w;
  cin >> w;
  sum[i][0] = mn[i][0] = w;
 }
 for (int j = 1; j < Lg; j++)
 {
  for (int i = 0; i < n; i++)
  {
   int p = up[i][j-1];
   up[i][j] = up[p][j-1];
   sum[i][j] = sum[i][j-1] + sum[p][j-1];
   mn[i][j] = min(mn[i][j-1], mn[p][j-1]);
  }
 }
 for (int i = 0; i < n; i++)
 {
  ll S = 0;
  int M = 1e9;
  ll rem = k;
  int node = i;
  for (int j = Lg - 1; j >= 0; j--)
  {
   ll jump = 1LL<<j;
   if (jump <= rem)
   {
    rem -= jump;
    M = min(M, mn[node][j]);
    S += sum[node][j];
    node = up[node][j];
   }
  }
  cout << S << ' ' << M << '\n';
 }
}
