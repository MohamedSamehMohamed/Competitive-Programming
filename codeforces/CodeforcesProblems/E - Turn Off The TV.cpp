// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 2e5+9, Lg = 26, M = 3 * N;
int n;
int a[N][2], a1[M], spt[M][Lg], Log[M], pre[M];
int minquery(int l, int r)
{
  int sz = Log[r - l + 1];
  int li = spt[l][sz];
  int ri = spt[r-(1<<sz)+1][sz];
  return min(pre[li], pre[ri]);
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i][0] >> a[i][1];
    a1[i] = a[i][0];
    a1[n+i] = a[i][1];
    a1[2*n+i] = a[i][1] + 1;
  }
  sort(a1, a1+(3*n));
  int sz = unique(a1, a1 + (3*n)) - a1 ;
  for (int i = 0; i < n; i++)
  {
    int l = a[i][0] = lower_bound(a1, a1 + sz, a[i][0]) - a1;
    int r = a[i][1] = lower_bound(a1, a1 + sz, a[i][1]) - a1;
    pre[l]++;
    pre[r + 1]--;
  }
  pre[1]+=pre[0];
  spt[1][0] = 1;
  for (int i = 2; i < M; i++)
  {
    pre[i] += pre[i-1];
    Log[i] = Log[i>>1] + 1;
    spt[i][0] = i;
  }
  for (int i = 1; i < Lg; i++)
    for (int j = 0; j + (1<<i) <= M; j++)
      {
        int l = spt[j][i-1];
        int r = spt[j + (1<<(i-1))][i-1];
        spt[j][i] = pre[l] < pre[r] ? l : r;
      }
  int ans = -1;
  for (int i = 0; i < n; i++)
  {
    int mn = minquery(a[i][0], a[i][1]);
    if (mn > 1)ans = i+1;
  }
  cout << ans <<"\n";
 
 
}
