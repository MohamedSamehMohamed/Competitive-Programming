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
const int N = 1e5 + 3;
int n, m, x, y;
string a[1000];
void test ()
{
  cin >> n >> m >> x >> y;
  for (int i =0; i < n ;i++)
  {
    cin >> a[i];
  }
  int need =0 ;
  for (int i =0; i < n ;i++)
  {
    for (int j =0 ; j < m ;j++)
    {
      need += ( a[i][j] == '.');
    }
  }
  int ans = need * x;
  int cur = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] != '.')continue;
      if (j + 1 < m && a[i][j+1] =='.')
      {
        cur += y;
        j++;
      }else
      {
        cur += x;
      }
    }
  }
  ans = min(ans, cur);
  cout << ans <<"\n";
 
}
int main()
{
  int t;
  cin >> t;
  while (t--)test();
}
