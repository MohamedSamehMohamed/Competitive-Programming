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
int p, n, u, v;
string x;
const int N = 101;
bool mat[N][N];
bool vis[N];
void get_int()
{
  u = v = 0;
  int i = 0;
  while(i < SZ(x) && x[i] != ' ')
  {
    u = u*10 + x[i]-'0';
    i++;
  }
  swap(u, v);
  i++;
  while(i < SZ(x) && x[i] != ' ')
  {
    u = u*10 + x[i]-'0';
    i++;
  }
  swap(u, v);
  u--;v--;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    memset(vis, 0, sizeof vis);
    memset(mat, 0, sizeof mat);
    cin >> p >> n;
    cin.ignore();
    while(getline(cin , x))
    {
      if (SZ(x) == 0)break;
      get_int();
      // u is the person
      mat[u][v] = 1;
    }
    int ans = 0;
    for (int i = 0; i < p; i++)
    {
      if (vis[i])continue;
      for (int j = i+1; j < p; j++)
      {
        if (vis[j])continue;
        bool same = 1;
        for (int id = 0; id < n; id++)
          if(mat[j][id] != mat[i][id])
          {
            same = 0;
            break;
          }
        vis[j] |= same;
      }
      ans++;
    }
    cout << ans << '\n';
    if (t)cout << '\n';
  }
}
