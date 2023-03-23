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
const int N = 100;
int n;
string x[N];
bool vis[N][N];
void dfs(int i, int j)
{
  vis[i][j] =1 ;
  if (i+1 < n && x[i+1][j] !='.')
  {
    while (i+1 < n && x[i+1][j] !='.')
    {
      i++;
      vis[i][j] = 1;
    }
  }else if (j+1 < n && x[i][j+1] !='.')
  {
    while (j+1 < n && x[i][j+1] !='.')
    {
      j++;
      vis[i][j] = 1;
    }
  }
}
void test()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  memset(vis, 0, sizeof vis);
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (x[i][j]== 'x' && !vis[i][j])
      {
        dfs(i, j);
        ans++;
      }
    }
  }
  printf("%d\n", ans);
}
int main()
{
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
    printf("Case %d: ", i);
    test();
  }
}
