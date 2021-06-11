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
const int N = 35;
int a[N][N], dist[3*N][2], n, m;
void test()
{
  cin >> n >> m;
  int best = 0;
  int b = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j], b += a[i][j];
  memset(dist, 0, sizeof dist);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      dist[i+j][ a[i][j] ]++;
    }
  }
  int ans = 0;
  int path_len = n + m - 2;
  for (int i = 0; i <= path_len; i++)
  {
    if (path_len - i == i)continue;
    int A = dist[i][0];
    int B = dist[i][1];
    int A1 = dist[path_len-i][0];
    int B1 = dist[path_len-i][1];
    ans += min( A + A1, B + B1 );
  }
  best = min(b, n*m - b);
  best = min(best, ans/2);
  cout << best <<"\n";
}
int main()
{
  int t;
  cin >> t;
  while (t--)test();
}
