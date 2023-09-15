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
const int N = 200, M = (1<<10);
int n, m;
int a[N], b[M];
bool solve (int msk)
{
  for (int i = 0; i < n; i++)
  {
    bool ok = 0;
    for (int j = 0; j < (1<<9); j++)
    {
      if (b[j] == 0)continue;
      int cur = (a[i] & j);
      if ((cur | msk) == msk)
      {
        ok = 1;
        break;
      }
    }
    if (!ok)return 0;
  }
  return 1;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    int x;cin >> x;
    b[x] = 1;
  }
  int ans = 1e9;
  for (int i = 0; i < (1<<9); i++)
  {
    if (solve(i)) ans = min(ans, i);
  }
  cout << ans <<"\n";
}
