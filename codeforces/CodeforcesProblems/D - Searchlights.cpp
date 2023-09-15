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
const int N = 2e3+9, M = 1e6+1;
int n, m;
int a[N], b[N], c[N], d[N];
int best[M];
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d%d", a+i, b+i);
  for (int i = 0; i < m; i++)
    scanf("%d%d", c+i, d+i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (c[j] - a[i] < 0)continue;
      best[c[j] - a[i]] = max(best[c[j] - a[i]], d[j] - b[i] + 1);
    }
 
  int ans = 1e9, mx = 0;
  for (int i = M-1; i >= 0; i--){
    mx = max(mx, best[i]);
    ans = min(ans, i + mx);
  }
  printf("%d\n", ans);
}
