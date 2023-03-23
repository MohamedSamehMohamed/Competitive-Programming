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
int n, m;
int Msk[60];
int ans[1<<20];
void test()
{
  memset(ans, -1, sizeof ans);
  cin >> n >> m;
  for (int i =0 ; i < m; i++)
  {
    int k;
    cin >> k;
    int msk = 0;
    while (k--)
    {
      int idx;
      cin >> idx;
      msk|=(1<<idx);
    }
    Msk[i] = msk;
  }
  queue<pair<int,int>> q;
  q.push({0, 0});
  ans[0] = 0;
  while (!q.empty())
  {
      auto cur = q.front();
      q.pop();
      for (int i = 0; i < m; i++)
      {
        int nmsk = cur.f;
        nmsk ^= Msk[i];
        if (ans[nmsk] == -1)
        {
          ans[nmsk] = cur.s + 1;
          q.push({nmsk, cur.s + 1});
        }
      }
  }
  int qi;
  cin >> qi;
  while(qi--)
  {
    string x;
    cin >> x;
    int qmsk =0;
    for (int i = n-1, j =0; ~i; i--, j++)
    {
      if (x[i] =='1')qmsk|=(1<<j);
    }
    cout << ans[qmsk] <<"\n";
  }
}
int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout <<"Case " << i+1 <<":\n";
    test();
    cout <<"\n";
  }
}
