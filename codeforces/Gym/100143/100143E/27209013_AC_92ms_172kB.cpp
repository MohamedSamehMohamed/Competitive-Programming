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
const int N = 60;
int n, m;
int a[N][N];
int b[N][N];
void setC(int j)
{
  for (int i = 0; i < n; i++)b[i][j] = 1;
}
void setR(int j)
{
  for (int i = 0; i < m; i++)b[j][i] = 1;
}
int main()
{
  freopen("bwsquare.in", "r", stdin);
  freopen("bwsquare.out", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
  vector<int> ans, ans1;
  for (int i = 0; i < n; i++)
  {
    bool bl = 1;
    for (int j = 0; j < m; j++)
    {
      bl&=(a[i][j]);
    }
    if (!bl)continue;
    ans.pb(-(i+1));
    for (int j = 0; j < m; j++)b[i][j] = 1;
  }
  for (int i = 0; i < m; i++)
  {
    bool bl = 1;
    for (int j = 0; j < n; j++)
    {
      bl&=(a[j][i]);
    }
    if (!bl)continue;
    bool need = 0;
    for (int j = 0; j < n; j++)
      if (b[j][i] == 0)
      {
        b[j][i] = 1;
        need = 1;
      }
    if (need) ans.pb((i+1));
  }

  bool same1 = 1, same2 = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      same1&=(a[i][j] == b[i][j]);
      memset(b, 0, sizeof b);

      for (int i = 0; i < m; i++)
      {
        bool bl = 1;
        for (int j = 0; j < n; j++)
        {
          bl&=(a[j][i]);
        }
        if (!bl)continue;
        bool need = 0;
        for (int j = 0; j < n; j++)
          if (b[j][i] == 0)
          {
            b[j][i] = 1;
            need = 1;
          }
        if (need) ans1.pb((i+1));
      }
      for (int i = 0; i < n; i++)
      {
        bool bl = 1;
        for (int j = 0; j < m; j++)
        {
          bl&=(a[i][j]);
        }
        if (!bl)continue;
        bool need = 0;
        for (int j = 0; j < m; j++)
          if (b[i][j] == 0)
          {
            b[i][j] = 1;
            need = 1;
          }
        if (need)
        ans1.pb(-(i+1));
      }

      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          same2&=(a[i][j] == b[i][j]);
  if (!same1 && !same2)
  {
    cout <<"-1\n";
    return 0;
  }
  if (same1 && same2)
  {
    if (SZ(ans1) < SZ(ans))ans = ans1;
  }else if (same2)ans = ans = ans1;
  cout << SZ(ans) <<"\n";
  for (int i: ans)cout << i <<" ";
  cout <<"\n";

}
