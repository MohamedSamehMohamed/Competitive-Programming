// Author : Mohamed Sameh
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
const int N = 2e5, M = 1e6+9;
int a[N][2], frq[M][2], ans[N], n, st, en;
int main()
{
  memset(frq, -1, sizeof frq);
  cin >> n;
  set<int> St;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i][0] >> a[i][1];
    if (a[i][0] == 0)st = i;
    if (a[i][1] == 0)en = i;
    frq[a[i][0]][0] = i;
    frq[a[i][1]][1] = i;
    St.insert(a[i][1]);
  }
  for (int i = 0; i < n; i++)
    if (St.find(a[i][0]) == St.end())
    {
      ans[0] = a[i][0];
      break;
    }
  ans[1]   = a[st][1];
  ans[n-2] = a[en][0];
  for (int i = 1; i + 1 < n; i++)
  {
    int idx = frq[ans[i-1]][0];
    if (~idx)
      ans[i+1] = a[idx][1];
    else
      break;
  }
  for (int i = n-3; i > 0; i--)
  {
    int idx = frq[ans[i+1]][1];
    if (~idx)
      ans[i-1] = a[idx][0];
    else
      break;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i+1 == n];
}
/*
5
0 4
5 3
4 1
3 2
1 0

*/
